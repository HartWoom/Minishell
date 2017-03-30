/*
** get_next_line.c for GNL in /home/antoine.hartwig/Epitech/CPE_2016/CPE_2016_getnextline
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Thu Jan 12 11:43:17 2017 Antoine Hartwig
** Last update Thu Mar 30 09:49:15 2017 HartWoom
*/

#include "my.h"

char	*my_strcp(char *src, char *dest)
{
  int	i;

  if ((dest = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char    *my_strcat(char *dest, char *src)
{
  char  *new;
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (dest[i++] != '\0');
  while (src[j++] != '\0');
  if (!(new = malloc(sizeof(char) * ((i - 1) + (j - 1) + 1))))
    return (NULL);
  i = 0;
  j = 0;
  while (dest[i] != '\0')
    {
      new[i] = dest[i];
      i++;
    }
  while (src[j] != '\0')
    {
      new[i] = src[j];
      i++;
      j++;
    }
  new[i] = '\0';
  return (new);
}

char	*my_strdup(char *str)
{
  char	*malloced;
  int	i;
  int	j;

  if (str == NULL)
    return (NULL);
  j = 0;
  while (str[j++] != '\0');
  i = -1;
  if ((str == NULL)
      || ((malloced = malloc(sizeof(char) * ((j - 1) + 1))) == NULL))
    return (NULL);
  while (str[++i])
    {
      malloced[i] = str[i];
      if (str[i] == '\n')
	break;
    }
  malloced[i] = 0;
  return (malloced);
}

char	*cut_str(char *str)
{
  char	*new;
  int	i = 0;
  int	j = 0;
  int	x = 0;

  if (str == NULL)
    return (NULL);
  while ((str[i] != '\n') && (str[i] != '\0'))
    i++;
  //  i++;
  while (str[x] != '\0')
    x++;
  if ((new = malloc(sizeof(char) * ((x - 1) - i + 2))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[j] = str[i];
      i++;
      j++;
    }
  new[j] = '\0';
  if (new[0] == '\0')
    return (NULL);
  return (new);
}

char		*get_next_line(const int fd)
{
  static char	*str = NULL;
  char		*buffer;
  int		size;
  static int	flag = 0;

  if ((fd <= -1) || (READ_SIZE < 1) || (flag == 1)
      || ((buffer = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL))
    return (NULL);
  while ((size = read(fd, buffer, READ_SIZE)) != 0)
    {
      buffer[size - 1] = '\0';
      if (str != NULL)
	str = my_strcat(str, buffer);
      else
	if ((str = my_strcp(buffer, str)) == NULL)
	  return (NULL);
      free(buffer);
      if ((buffer = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
      	return (NULL);
      if (size != READ_SIZE)
	break;
    }
  buffer = my_strdup(str);
  if ((str = cut_str(str)) == NULL)
    flag = 0;
  return (buffer);
}
