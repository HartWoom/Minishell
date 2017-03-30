/*
** pre_check.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 18:03:28 2017 HartWoom
** Last update Thu Mar 30 10:33:49 2017 HartWoom
*/

#include "pre_check.h"
#include "usefull.h"
#include "my.h"

void	pre_check(t_shell *shell, char *str)
{
  char	**full_line;
  pid_t	w;
  int	status;

  if (str[0] != '\0')
    {
      full_line = cut_entry(str);
      if (my_builtins(shell, full_line) == 1)
	return;
      if ((w = fork()) == -1)
	return;
      if (w == 0)
	execute_entry(shell, full_line);
      else
	{
	  w = wait(&status);
	}
      free(full_line);
    }
}
