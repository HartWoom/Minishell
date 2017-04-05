/*
** my_change_dir.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2/my_builtins
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Mar 23 15:38:23 2017 HartWoom
** Last update Wed Apr  5 18:47:21 2017 HartWoom
*/

#include "my_builtins.h"
#include "struct.h"
#include "usefull.h"

char	*replace_tild(t_shell *shell, char **full_line)
{
  int	i = 0;
  int	j = 1;
  char	*save;

  if (!(save = malloc(sizeof(char) * (my_strlen(full_line[1])
				      + my_strlen(shell->HOME) + 1))))
    exit(84);
  while (shell->HOME[i] != '\0')
    {
      save[i] = shell->HOME[i];
      i++;
    }
  while (full_line[1][j] != '\0')
    {
      save[i] = full_line[1][j];
      i++;
      j++;
    }
  return (save);
}

int	my_change_dir(t_shell *shell, char **full_line)
{
  int	fd;
  int	i = 0;

  while (full_line[i] != NULL)
    i++;
  if (i == 1)
    return (chdir(shell->HOME) + 1);
  else if (i == 2)
    {
      if (full_line[1][0] == '~')
	full_line[1] = replace_tild(shell, full_line);
      if (chdir(full_line[1]) == -1)
	{
	  if ((fd = open(full_line[1], O_RDONLY)) != -1)
	    my_printf("%s: Not a directory.\n", full_line[1]);
	  else
	    my_printf("%s: No such file or directory.\n", full_line[1]);
	  if (fd != -1)
	    close(fd);
	  return (1);
	}
    }
  return (1);
}
