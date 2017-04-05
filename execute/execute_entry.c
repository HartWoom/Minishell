/*
** execute_entry.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Mar 30 10:02:27 2017 HartWoom
** Last update Wed Apr  5 17:55:03 2017 HartWoom
*/

#include "struct.h"
#include "execute.h"

void	execute_entry(t_shell *shell, char **full_line)
{
  char	*save;
  int	i = 0;

  execve(full_line[0], full_line, shell->env);
  save = my_strcp(full_line[0]);
  while (shell->PATH[i] != NULL)
    {
      full_line[0] = my_strcat(shell->PATH[i], full_line[0]);
      execve(full_line[0], full_line, shell->env);
      full_line[0] = my_strcp(save);
      i++;
    }
  my_printf("%s: Command not found.\n", save);
  exit(1);
}
