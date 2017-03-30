/*
** my_strcp.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Mar 30 10:34:23 2017 HartWoom
** Last update Thu Mar 30 10:38:58 2017 HartWoom
*/

#include <stdlib.h>
#include "usefull.h"

char	*my_strcp(char *src)
{
  char	*new;
  int	i = 0;

  if (!(new = malloc(sizeof(char) * (my_strlen(src) + 1))))
    exit(84);
  while (src[i] != '\0')
    {
      new[i] = src[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}
