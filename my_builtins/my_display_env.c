/*
** my_display_env.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Fri Mar 24 09:31:17 2017 HartWoom
** Last update Fri Apr  7 18:22:28 2017 HartWoom
*/

#include "struct.h"
#include "my_builtins.h"
#include "usefull.h"

int	my_display_env(t_shell *shell)
{
  int	i = 0;

  while (shell->env[i] != NULL)
    {
      my_printf("%s\n", shell->env[i]);
      i++;
    }
  shell->exit_status = 0;
  return (1);
}
