/*
** set_envp.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Mar 30 10:06:05 2017 HartWoom
** Last update Thu Mar 30 10:30:14 2017 HartWoom
*/

#include <unistd.h>
#include <stdlib.h>

char	**set_envp()
{
  char	**envp;

  if (!(envp = malloc(sizeof(char *) * 1)))
    exit(84);
  if (!(envp[0] = malloc(sizeof(char) * 1)))
    exit(84);
  envp[0] = NULL;
  return (envp);
}
