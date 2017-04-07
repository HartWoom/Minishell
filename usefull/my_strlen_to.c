/*
** my_strlen_to.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 17:17:23 2017 HartWoom
** Last update Fri Apr  7 11:09:35 2017 HartWoom
*/

#include "my.h"

int		my_strlen_to_space(char *str, int flag)
{
  static int	i = 0;

  if (flag == 0)
    i = 0;
  while (str[i] == ' ')
    i++;
  while (str[i] != '\0' && str[i] != ' ')
    i++;
  return (i - 1);
}

int		my_strlen_to_point(char *str)
{
  static int	i = 0;

  while (str[i] != '\0' && str[i] != ':')
    {
      i++;
    }
  return (i - 1);
}
