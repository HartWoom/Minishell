/*
** main.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 10:05:16 2017 HartWoom
** Last update Wed Apr  5 17:53:55 2017 HartWoom
*/

#include "my.h"
#include "struct.h"
#include "usefull.h"

void	in_a_tty(t_shell *shell)
{
  char	*str;

  my_printf("$$> ");
  while ((str = get_next_line(0)))
    {
      pre_check(shell, str);
      my_printf("$$> ");
      free(str);
    }
}

int		main(int ac, char **av, char **env)
{
  t_shell	*shell;

  if (ac != 1)
    return (84);
  av[0][0] = 'p';
  if (!(shell = malloc(sizeof(t_shell))))
    return (84);
  set_struct(shell, env);
  /* if (isatty(0) == 0) */
  /*   not_a_tty(shell); */
  in_a_tty(shell);
  return (0);
}
