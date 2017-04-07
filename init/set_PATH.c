/*
** set_PATH.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 10:30:21 2017 HartWoom
** Last update Fri Apr  7 10:55:26 2017 HartWoom
*/

#include "init.h"

char		*my_strcp_PATH(char *str, char *dest)
{
  static int	i = 0;
  static int	flag = 0;
  int		j = 0;

  if  (flag == 0)
    {
      while (str[++i] != '=');
      i++;
      flag = 1;
    }
  while (str[i] != '\0' && str[i] != ':')
    {
      dest[j] = str[i];
      i++;
      j++;
    }
  dest[j] = '/';
  dest[j + 1] = '\0';
  i++;
  return (dest);
}

char	**cut_PATH(char *str)
{
  char	**new;
  int	i = 0;
  int	k = -1;

  while (str[++k] != '\0')
    if (str[k] == ':' || str[k] == '\0')
      i++;
  if (!(new = malloc(sizeof(char *) * (i + 2))))
    exit(84);
  new[i + 1] = NULL;
  k = 0;
  while (k != i + 1)
    {
      if (!(new[k] = malloc(sizeof(char) * (my_strlen_to_point(str) + 2))))
	exit(84);
      new[k] = my_strcp_PATH(str, new[k]);
      k++;
    }
  new[k] = '\0';
  return (new);
}

char    **set_PATH(char **env)
{
  int   i = 0;

  while (env[i] != NULL)
    {
      if (str_finder(env[i], "PATH") == 0)
	return (cut_PATH(env[i]));
      i++;
    }
  return (NULL);
}
