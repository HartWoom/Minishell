/*
** cut_entry.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 15:32:43 2017 HartWoom
** Last update Wed Apr 12 13:17:50 2017 HartWoom
*/

#include "my.h"

int		little_epur(char *str, int flag)
{
  static int	i = 0;
  int		k = 0;

  if (flag == 0)
    i = 0;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == ';')
    i++;
  while (str[i] != '\0' && str[i] != ';')
    {
      if (str[i] == '|' || str[i] == '<' || str[i] == '>')
	exit(0);
      if ((str[i] == ' ' || str[i] == '\t')
	  && (str[i + 1] != ' ' && str[i + 1] != '\t'
	      && str[i + 1] != '\0' && str[i + 1] != ';'))
	k++;
      i++;
    }
  return (k);
}

char		*my_str_copy_entry(char *src, char *dest, int flag)
{
  static int	i = 0;
  int		j = 0;

  if (flag == 0)
    i = 0;
  j = 0;
  while (src[i] == ' ' || src[i] == '\t' || src[i] == ';')
    i++;
  while (src[i] != '\0' && src[i] != ' ' && src[i] != '\t' && src[i] != ';')
    {
      dest[j] = src[i];
      i++;
      j++;
    }
  dest[j] = '\0';
  i++;
  return (dest);
}

char	**cut_entry(char *str, int colons)
{
  char	**new;
  int	i = 0;
  int	l = 0;
  int	flag = 0;

  if (colons == 1)
    flag = 1;
  l = little_epur(str, flag);
  if (!(new = malloc(sizeof(char *) * (l + 2))))
    exit(84);
  new[l + 1] = NULL;
  while (i != l + 1)
    {
      if (!(new[i] = malloc(sizeof(char)
			    * (my_strlen_to_space(str, flag) + 2))))
	exit(84);
      new[i] = my_str_copy_entry(str, new[i], flag);
      i++;
      flag = 1;
    }
  return (new);
}
