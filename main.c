/*
** main.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 10:05:16 2017 HartWoom
** Last update Mon Mar 20 15:01:39 2017 HartWoom
*/

#include "my.h"

int		main(int ac, char **av, char **env)
{
  t_shell	*shell;

  if (ac != 1)
    return (84);
  if (!(shell = malloc(sizeof(t_shell))))
    return (84);
  set_struct(shell, env);
}
