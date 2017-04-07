/*
** add_one.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Apr  6 23:25:15 2017 HartWoom
** Last update Fri Apr  7 09:24:23 2017 HartWoom
*/

#include "usefull.h"
#include "struct.h"
#include "setenv.h"

void	add_one(t_shell *shell, char **full_line, int size)
{
  char  **save;
  int   i = 0;

  if (!(save = malloc(sizeof(char *) * (shell->total_env + 1))))
    exit(84);
  while (i != shell->total_env)
    {
      if (!(save[i] = malloc(sizeof(char) * (my_strlen(shell->env[i]) + 1))))
	exit(84);
      save[i] = my_strcp(shell->env[i]);
      i++;
    }
  shell->total_env++;
  if (!(shell->env = malloc(sizeof(char *) * (shell->total_env + 1))))
    exit(84);
  i = 0;
  while (i != shell->total_env - 1)
    {
      if (!(shell->env[i] = malloc(sizeof(char) * (my_strlen(save[i]) + 1))))
	exit(84);
      shell->env[i] = my_strcp(save[i]);
      i++;
    }
  if (size == 2)
    {
      if (!(shell->env[i] = malloc(sizeof(char) * (my_strlen(full_line[1] + 2)))))
	exit(84);
      shell->env[i] = my_strcat(full_line[1], "=");
    }
  else if (size == 3)
    {
      if (!(shell->env[i] = malloc(sizeof(char) * (my_strlen(full_line[1])
						   + my_strlen(full_line[2]) + 2))))
	exit(84);
      shell->env[i] = my_strcat(full_line[1], "=");
      shell->env[i] = my_strcat(shell->env[i], full_line[2]);
    }
  shell->env[i + 1] = NULL;
  free(save);
}
