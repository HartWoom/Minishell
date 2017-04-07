/*
** remove_one.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2/my_builtins
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Apr  4 17:40:46 2017 HartWoom
** Last update Fri Apr  7 10:33:00 2017 HartWoom
*/

#include "unsetenv.h"
#include "struct.h"

void	remove_one_p2(t_shell *shell, char **save, int size)
{
  int	i = 0;

  free(shell->env);
  if (!(shell->env = malloc(sizeof(char *) * size)))
    exit(84);
  while (i != size - 1)
    {
      if (!(shell->env[i] = malloc(sizeof(char) * (my_strlen(save[i]) + 1))))
	exit(84);
      shell->env[i] = my_strcp(save[i]);
      i++;
    }
  shell->env[i] = NULL;
}

void	remove_one(t_shell *shell, int k)
{
  char	**save;
  int	i = 0;
  int	flag = 0;
  int	size = 0;

  while (shell->env[size] != NULL)
    size++;
  if (!(save = malloc(sizeof(char *) * size)))
    exit(84);
  while (shell->env[i] != NULL)
    {
      if (i != k)
	{
	  if (!(save[i - flag] = malloc(sizeof(char) * (my_strlen(shell->env[i] + 1)))))
	    exit(84);
	  save[i - flag] = my_strcp(shell->env[i]);
	}
      else
	flag += 1;
      i++;
    }
  remove_one_p2(shell, save, size);
  free(save);
}
