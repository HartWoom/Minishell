/*
** my.h for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 10:06:39 2017 HartWoom
** Last update Mon Mar 20 14:52:25 2017 HartWoom
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>

typedef struct s_shell
{
  char	**PATH;
  char	*HOME;
}	t_shell;

void	my_putchar(char);
void	my_putstr(char *);
void	my_put_nbr(int);
int	my_printf(char *, ...);
int	my_strlen(char *);
int	my_getnbr(char *);
void	set_struct(t_shell *, char **);
char	**set_PATH(char **);
char	*set_HOME(char **);
int	str_finder(char *, char *);

#endif
