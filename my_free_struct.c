/*
** my_free_struct.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Fri Apr  7 13:27:26 2017 HartWoom
** Last update Sun Apr  9 18:47:58 2017 HartWoom
*/

#include <stdlib.h>
#include "struct.h"

void	my_free_struct(t_shell *shell)
{
  free(shell->HOME);
  free(shell->PATH);
  free(shell->env);
}
