/*
** set_env.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Fri Mar 24 09:37:24 2017 HartWoom
** Last update Thu Apr  6 22:44:04 2017 HartWoom
*/

#include "init.h"
#include "struct.h"

char	**set_env(t_shell *shell, char **env)
{
  char	**new;
  int	i = 0;

  while (env[i] != NULL)
    i++;
  if (!(new = malloc(sizeof(char *) * (i + 1))))
    exit(84);
  i = 0;
  while (env[i] != NULL)
    {
      new[i] = env[i];
      i++;
    }
  shell->total_env = i;
  new[i] = NULL;
  return (new);
}
