/*
** remove_one.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2/my_builtins
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Apr  4 17:40:46 2017 HartWoom
** Last update Wed Apr  5 19:48:17 2017 HartWoom
*/

#include "unsetenv.h"
#include "struct.h"

/* void	remove_one_p2(t_shell *shell, char **save, int k) */
/* { */
/*   int	i = 0; */
/*   int	j = 0; */

/*   free(shell->env); */
/*   if (!(shell->env = malloc(sizeof(char *) * (k - 1)))) */
/*     exit(84); */
/*   while (i != k - 1) */
/*     { */
      
/*     } */
/* } */

void	remove_one(t_shell *shell, char **full_line, int k, int size)
{
  char	**save;
  int	i = 0;
  int	j = 0;

  (void) (full_line);
  if (!(save = malloc(sizeof(char *) * size - 1)))
    exit(84);
  while (shell->env[i] != NULL)
    {
      if (i != k)
	{
	  if (!(save[i] = malloc(sizeof(char) * (my_strlen(shell->env[i] + 1)))))
	    exit(84);
	  while (shell->env[i][j] != '\0')
	    {
	      save[i][j] = shell->env[i][j];
	      j++;
	    }
	}
      i++;
      j = 0;
    }
  //  remove_one_p2(shell, save, k);
}
