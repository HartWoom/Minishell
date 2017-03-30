/*
** set_env.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Fri Mar 24 09:37:24 2017 HartWoom
** Last update Wed Mar 29 09:40:40 2017 HartWoom
*/

#include "init.h"
#include "struct.h"

void	set_env(t_shell *shell, char **env)
{
  int	i = 0;

  while (env[i] != NULL)
    i++;
  if (!(shell->env = malloc(sizeof(char *) * (i + 1))))
    exit(84);
  i = 0;
  while (env[i] != NULL)
    {
      shell->env[i] = env[i];
      i++;
    }
  shell->env[i] = NULL;
}
