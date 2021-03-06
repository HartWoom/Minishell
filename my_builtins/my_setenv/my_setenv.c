/*
** my_setenv.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Mar 30 11:13:59 2017 HartWoom
** Last update Sun Apr  9 16:44:58 2017 HartWoom
*/

#include "setenv.h"
#include "struct.h"

int	my_setenv_error(t_shell *shell, int i)
{
  if (i == 1)
    return (my_display_env(shell) - 1);
  else if (i > 3)
    {
      my_printf("setenv: Too many argument.\n");
      shell->exit_status = 1;
      return (0);
    }
  return (i);
}

char	*set_malloc_env(char **full_line, int size)
{
  char	*new;

  if (size == 3)
    {
      if (!(new = malloc(sizeof(char) * (my_strlen(full_line[1])
					 + my_strlen(full_line[2]) + 2))))
	exit(84);
    }
  else
    if (!(new = malloc(sizeof(char) * (my_strlen(full_line[1] + 2)))))
      exit(84);
  return (new);
}

char	*modify_env(char *str, char **full_line, int size)
{
  int	i = 0;
  int	j = 0;

  str = set_malloc_env(full_line, size);
  while (full_line[1][i] != '\0')
    {
      str[i] = full_line[1][i];
      i++;
    }
  str[i] = '=';
  i++;
  if (size == 3)
    while (full_line[2][j] != '\0')
      {
	str[i] = full_line[2][j];
	i++;
	j++;
      }
  str[i] = '\0';
  return (str);
}

int	my_setenv(t_shell *shell, char **full_line)
{
  int	size = 0;
  int	i = 0;

  while (full_line[i] != NULL)
    i++;
  if ((size = my_setenv_error(shell, i)) == 0)
    return (1);
  i = 0;
  while (shell->env[i] != NULL)
    {
      if (str_finder(shell->env[i], full_line[1]) == 0)
	break;
      i++;
    }
  if (shell->env[i] != NULL)
    shell->env[i] = modify_env(shell->env[i], full_line, size);
  else
    add_one(shell, full_line, size);
  shell->exit_status = 0;
  return (1);
}
