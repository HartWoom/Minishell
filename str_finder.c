/*
** str_finder.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 10:37:27 2017 HartWoom
** Last update Mon Mar 20 10:38:59 2017 HartWoom
*/

#include "my.h"

int     str_finder(char *str1, char *str2)
{
  int   i = -1;

  if (my_strlen(str1) < 4)
    return (1);
  while (++i != 3)
    if (str1[i] != str2[i])
      return (1);
  return (0);
}
