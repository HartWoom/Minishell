/*
** my_builtins.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 18:53:26 2017 HartWoom
** Last update Mon Apr  3 13:24:35 2017 HartWoom
*/

#include "my.h"
#include "usefull.h"
#include "my_builtins.h"

int	my_builtins(t_shell *shell, char **full_line)
{
  if (my_str_cmp(full_line[0], "exit") == 0 && full_line[1] == NULL)
    my_put_exit("exit\n", 0);
  else if (my_str_cmp(full_line[0], "cd") == 0)
    return (my_change_dir(shell, full_line));
  else if (my_str_cmp(full_line[0], "env") == 0 && full_line[1] == NULL)
    return (my_display_env(shell));
  else if (my_str_cmp(full_line[0], "setenv") == 0)
    return (my_setenv(shell, full_line));
  else if (my_str_cmp(full_line[0], "unsetenv") == 0)
    return (my_unsetenv(shell, full_line));
  return (0);
}
