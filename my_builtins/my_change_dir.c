/*
** my_change_dir.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2/my_builtins
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Mar 23 15:38:23 2017 HartWoom
** Last update Fri Apr  7 16:14:08 2017 HartWoom
*/

#include <unistd.h>
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

int	display_correct_error(char **full_line)
{
  int	fd;

  if ((fd = open(full_line[1], O_RDONLY)) != -1)
    my_printf("%s: Not a directory.\n", full_line[1]);
  else
    my_printf("%s: No such file or directory.\n", full_line[1]);
  if (fd != -1)
    close(fd);
  return (1);
}

void	replace_oldpwd(t_shell *shell, char *old)
{
  char	**pwd;

  if (!(pwd = malloc(sizeof(char *) * 4)))
    exit(84);
  if (!(pwd[2] = malloc(sizeof(char) * my_strlen(old))))
    exit(84);
  pwd[0] = "setenv";
  pwd[1] = "OLDPWD";
  pwd[2] = old;
  pwd[3] = NULL;
  my_setenv(shell, pwd);
  free(pwd);
  if (!(pwd = malloc(sizeof(char *) * 4)))
    exit(84);
  if (!(pwd[2] = malloc(sizeof(char) * 1024)))
    exit(84);
  pwd[0] = "setenv";
  pwd[1] = "PWD";
  pwd[2] = getcwd(pwd[2], 1024);
  pwd[3] = NULL;
  my_setenv(shell, pwd);
  free(pwd);
  shell->exit_status = 0;
}

void	return_to_old_dir(t_shell *shell, char **full_line)
{
  int	i = 0;

  if (my_strlen(full_line[1]) > 1)
    {
      my_printf("Usage: cd [-plvn][-|<dir>].\n");
      shell->exit_status = 1;
    }
  else
    {
      while (str_finder(shell->env[i], "OLDPWD") != 0 && shell->env[i] != NULL)
	i++;
      if (shell->env[i] == NULL)
	{
	  my_printf(": No such file or directory.\n");
	  shell->exit_status = 1;
	}
      else
	chdir(shell->env[i] + 7);
    }
}

int	my_change_dir(t_shell *shell, char **full_line)
{
  int	i = 0;
  char	*tmp;
  char	*old;

  old = malloc(sizeof(char) * 1024);
  old[1023] = '\0';
  getcwd(old, 1024);
  tmp = malloc(sizeof(char) * 1024);
  tmp[1023] = '\0';
  while (full_line[i] != NULL)
    i++;
  if (i == 1)
    chdir(shell->HOME);
  else if (i == 2)
    {
      if (full_line[1][0] == '-')
      	return_to_old_dir(shell, full_line);
      else if (full_line[1][0] == '~')
	full_line[1] = replace_tild(shell, full_line);
      if (chdir(full_line[1]) == -1 && full_line[1][0] != '-')
	display_correct_error(full_line);
    }
  if (my_str_cmp(old, getcwd(tmp, 1024)) != 0)
    replace_oldpwd(shell, old);
  return (1);
}
