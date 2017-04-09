/*
** pre_check.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 18:03:28 2017 HartWoom
** Last update Sun Apr  9 16:18:28 2017 HartWoom
*/

#include "pre_check.h"
#include "usefull.h"
#include "my.h"

void	non_fork_part(t_shell *shell, int status)
{
  if (WIFSIGNALED(status) == 1)
    {
      if (WTERMSIG(status) == 11)
	{
	  shell->exit_status = 139;
	  my_printf("Segmentation fault (core dumped)\n");
	}
      if (WTERMSIG(status) == 8)
	{
	  shell->exit_status = 136;
	  my_printf("Floating exception (core dumped)\n");
	}
    }
  else if (WIFEXITED(status) == 1)
    shell->exit_status = WEXITSTATUS(status);
}

int	pre_check(t_shell *shell, char *str)
{
  char	**full_line;
  pid_t	w;
  int	status;
  int	i = 0;

  if (str[0] != '\0')
    {
      full_line = cut_entry(str);
      i = my_builtins(shell, full_line);
      if (i == 1 || i == -1)
	return (i - 1);
      if ((w = fork()) == -1)
	return (0);
      if (w == 0)
	execute_entry(shell, full_line);
      else
	{
	  w = wait(&status);
	  non_fork_part(shell, status);
	}
      free(full_line);
    }
  return (0);
}
