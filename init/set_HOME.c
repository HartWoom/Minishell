/*
** set_HOME.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 14:49:16 2017 HartWoom
** Last update Fri Mar 24 09:56:21 2017 HartWoom
*/

#include "init.h"
#include "usefull.h"

char	*cut_HOME(char *str)
{
  char	*new;
  int	i = 0;
  int	j = 0;

  while (str[++i] != '=');
  if (!(new = malloc(sizeof(char) * (my_strlen(str) - i + 1))))
    exit(84);
  i++;
  while (str[i] != '\0')
    {
      new[j] = str[i];
      i++;
      j++;
    }
  new[j] = '\0';
  return (new);
}

char	*set_HOME(char **env)
{
  int	i = 0;

  while (env[i] != NULL)
    {
      if (str_finder(env[i], "HOME") == 0)
	return (cut_HOME(env[i]));
      i++;
    }
  return (NULL);
}
