/*
** my_change_dir.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2/my_builtins
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Mar 23 15:38:23 2017 HartWoom
** Last update Fri Mar 24 09:29:28 2017 HartWoom
*/

#include "my_builtins.h"
#include "struct.h"
#include "usefull.h"

int	my_change_dir(t_shell *shell, char **full_line)
{
  int	fd;
  int	i = 0;

  while (full_line[i] != NULL)
    i++;
  if (i == 1)
    return (chdir(shell->HOME) + 1);
  else if (i == 2)
    if (chdir(full_line[1]) == -1)
      {
        if ((fd = open(full_line[1], O_RDONLY)) != -1)
	  my_printf("%s: Not a directory.", full_line[1]);
	else
	  my_printf("%s: No such file or directory.", full_line[1]);
	return (1);
      }
  return (0);
}
