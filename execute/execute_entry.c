/*
** execute_entry.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Mar 30 10:02:27 2017 HartWoom
** Last update Thu Apr  6 20:07:59 2017 HartWoom
*/

#include "struct.h"
#include "execute.h"
#include "usefull.h"

void	execute_entry(t_shell *shell, char **full_line)
{
  char	*save;
  int	i = 0;
  int	size;

  size = my_strlen(full_line[0]);
  execve(full_line[0], full_line, shell->env);
  save = my_strcp(full_line[0]);
  while (shell->PATH[i] != NULL)
    {
      /* if (!(full_line[0] = malloc(sizeof(char) * (size + my_strlen(shell->PATH[i] + 1))))) */
      /* 	exit(84); */
      full_line[0] = my_strcat(shell->PATH[i], save);
      execve(full_line[0], full_line, shell->env);
      free(full_line[0]);
      if (!(full_line[0] = malloc(sizeof(char) * (size + 1))))
      	exit(84);
      full_line[0] = my_strcp(save);
      i++;
    }
  my_printf("%s: Command not found.\n", save);
  free(full_line);
  exit(1);
}
