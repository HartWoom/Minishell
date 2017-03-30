/*
** my_put_exit.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 18:57:13 2017 HartWoom
** Last update Thu Mar 23 17:14:16 2017 HartWoom
*/

#include "my.h"
#include "usefull.h"

void	my_put_exit(char *str, int nb)
{
  my_putstr(str);
  exit(nb);
}
