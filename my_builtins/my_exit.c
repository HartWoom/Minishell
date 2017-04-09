/*
** my_exit.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Apr  6 20:10:03 2017 HartWoom
** Last update Sun Apr  9 18:59:00 2017 HartWoom
*/

#include "my_exit.h"
#include "struct.h"
#include "usefull.h"

int	return_index(char **full_line)
{
  int	i = 0;

  while (full_line[1][i] != '\0')
    {
      if (full_line[1][i] < '0' || full_line[1][i] > '9')
	break;
      i++;
    }
  return (i);
}

int	check_exit_arg(t_shell *shell, char **full_line)
{
  int	i = 0;

  i = return_index(full_line);
  if ((full_line[1][0] >= '0' && full_line[1][0] <= '9')
      && full_line[1][i] != '\0')
    {
      my_printf("exit: Badly formed number.\n");
      shell->exit_status = 1;
    }
  else if ((full_line[1][0] < '0' || full_line[1][0] > '9')
	   && full_line[1][i] != '\0')
    {
      my_printf("exit: Expression Syntax.\n");
      shell->exit_status = 1;
    }
  else if (full_line[1][i] == '\0')
    {
      shell->exit_status = my_getnbr(full_line[1]);
      my_printf("exit\n");
      return (-1);
    }
  return (0);
}

int	my_exit(t_shell *shell, char **full_line)
{
  int	i = 0;

  while (full_line[i] != NULL)
    i++;
  if (i > 2)
    {
      my_printf("exit: Expression Syntax.\n");
      shell->exit_status = 1;
    }
  else if (i == 2)
    {
      if (check_exit_arg(shell, full_line) == -1)
	return (-1);
    }
  else if (i == 1)
    {
      my_printf("exit\n");
      shell->exit_status = 0;
      free(full_line);
      return (-1);
    }
  return (0);
}
