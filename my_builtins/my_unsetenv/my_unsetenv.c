/*
** my_unsetenv.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Apr  3 13:18:27 2017 HartWoom
** Last update Fri Apr  7 18:40:32 2017 HartWoom
*/

#include "unsetenv.h"

void	unsetenv_error(t_shell *shell)
{
  my_printf("unsetenv: Too few arguments.");
  shell->exit_status = 1;
}

int	my_unsetenv(t_shell *shell, char **full_line)
{
  int	i = 0;
  int	j = 0;
  int	k = 1;

  while (full_line[i] != NULL)
    i++;
  if (i == 1)
    unsetenv_error(shell);
  while (full_line[k] != NULL)
    {
      while (shell->env[j] != NULL)
	{
	  if (str_finder(shell->env[j], full_line[k]) == 0)
	    {
	      remove_one(shell, j);
	      shell->total_env--;
	      break;
	    }
	  j++;
	}
      k++;
      j = 0;
    }
  shell->exit_status = 0;
  return (1);
}
