/*
** my_exit.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Apr  6 20:10:03 2017 HartWoom
** Last update Thu Apr  6 22:33:17 2017 HartWoom
*/

#include "my_exit.h"
#include "struct.h"

int	my_exit(char **full_line)
{
  free(full_line);
  my_printf("exit\n");
  return (-1);
}
