/*
** usefull.h for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Mar 23 17:09:55 2017 HartWoom
** Last update Sun Apr  9 18:37:22 2017 HartWoom
*/

#ifndef USEFULL_H_
# define USEFULL_H_

void    my_putchar(char);
void    my_putstr(char *);
void    my_put_exit(char *, int);
void    my_put_nbr(int);
int     my_printf(char *, ...);
int     my_strlen(char *);
int     my_getnbr(char *);
int     my_str_cmp(char *, char *);
char	*my_strcat(char *, char *);
char	*my_strcp(char *);

#endif
