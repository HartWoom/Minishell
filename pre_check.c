/*
** pre_check.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 18:03:28 2017 HartWoom
** Last update Wed Apr 12 13:40:13 2017 HartWoom
*/

#include "pre_check.h"
#include "usefull.h"
#include "my.h"

void	non_fork_part(t_shell *shell, int status)
{
  if (WIFSIGNALED(status) == 1)
    {
      shell->exit_status = WTERMSIG(status) + 128;
      if (WTERMSIG(status) == 11)
	my_printf("Segmentation fault (core dumped)\n");
      if (WTERMSIG(status) == 8)
	my_printf("Floating exception (core dumped)\n");
    }
  else if (WIFEXITED(status) == 1)
    shell->exit_status = WEXITSTATUS(status);
}

int	count_semicolons(char *str)
{
  int	i = 0;
  int	s = 0;
  int	flag = 0;

  while (str[i] == ';')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] != ';' && str[i] != '\t' && str[i] != ' ' && str[i] != '\0')
	flag = 1;
      if (str[i] == ';' && flag == 1)
	{
	  s++;
	  flag = 0;
	}
      i++;
    }
  return (s);
}

int	condition(t_shell *shell, char **full_line)
{
  pid_t	w;
  int	status = 0;

  if ((w = fork()) == -1)
    return (0);
  if (w == 0)
    execute_entry(shell, full_line);
  else
    {
      w = wait(&status);
      non_fork_part(shell, status);
    }
  return (0);
}

int	pre_check(t_shell *shell, char *str)
{
  char	**full_line;
  int	i = 0;
  int	j = 0;
  int	s;
  int	colons = 0;

  if (str[0] != '\0')
    {
      s = count_semicolons(str);
      while (j <= s)
	{
	  full_line = cut_entry(str, colons);
	  i = my_builtins(shell, full_line);
	  if (i == -1)
	    return (i - 1);
	  if (i != 1)
	    condition(shell, full_line);
	  free(full_line);
	  j++;
	  colons = 1;
	}
    }
  return (0);
}
