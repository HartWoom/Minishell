/*
** main.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 10:05:16 2017 HartWoom
** Last update Thu Apr  6 22:48:12 2017 HartWoom
*/

#include "my.h"
#include "struct.h"
#include "usefull.h"

void	process_loop(t_shell *shell, int tty)
{
  char	*str;

  if (tty == 0)
    {
      my_printf("$$> ");
      while ((str = get_next_line(0)))
	{
	  if (pre_check(shell, str) == -1)
	    {
	      free(str);
	      return;
	    }
	  my_printf("$$> ");
	  free(str);
	}
    }
  else
    {
      while ((str = get_next_line(0)) != NULL)
	{
	  if (pre_check(shell, str) == 1)
	    {
	      free(str);
	      return;
	    }
	  free(str);
	}
    }
}

int		main(int ac, char **av, char **env)
{
  t_shell	*shell;

  if (ac != 1)
    {
      free(av);
      return (84);
    }
  if (!(shell = malloc(sizeof(t_shell))))
    return (84);
  set_struct(shell, env);
  if (isatty(0) == 0)
    process_loop(shell, 1);
  else
    process_loop(shell, 0);
  free(shell);
  return (0);
}
