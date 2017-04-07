/*
** my_unsetenv.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Apr  3 13:18:27 2017 HartWoom
** Last update Fri Apr  7 11:30:17 2017 HartWoom
*/

#include "unsetenv.h"

int	*look_dup(char **full_line, char *envi, int *occ, int k)
{
  int	i = 0;

  while (i != k)
    {
      if (my_str_cmp(full_line[i], envi) == 0)
	{
	  occ[k] = 1;
	  break;
	}
      i++;
    }
  return (occ);
}

int	*compare_both(char *envi, char **full_line, int *occ)
{
  int	i = 0;
  int	j = 0;
  int	flag = 0;

  while (full_line[i] != NULL)
    {
      if (occ[i] == 0)
	{
	  if (my_strlen(envi) == my_strlen(full_line[i]))
	    while (envi[j] != '\0')
	      {
		if (envi[j] != full_line[i][j])
		  flag = 1;
		j++;
	      }
	}
      else
	flag = 1;
      if (flag == 0)
	occ = look_dup(full_line, envi, occ, i);
      j = 0;
      flag = 0;
      i++;
    }
  return (occ);
}

int	*set_occ(int *occ, int k)
{
  int	i = 0;

  if (!(occ = malloc(sizeof(int) * i)))
    exit(84);
  while (i != k)
    {
      occ[i] = 0;
      i++;
    }
  return (occ);
}

int	*count_occurence(t_shell *shell, char **full_line)
{
  int	*occ;
  int	i = 0;
  int	j = 0;

  while (full_line[i] != NULL)
    i++;
  //  occ = set_occ(occ, i);
  if (!(occ = malloc(sizeof(int) * i)))
    exit(84);
  while (j != i)
    {
      occ[j] = 0;
      j++;
    }
  i = 0;
  while (shell->env[i] != NULL)
    {
      occ = compare_both(shell->env[i], full_line, occ);
      i++;
    }
  return (occ);
}

int	my_unsetenv(t_shell *shell, char **full_line)
{
  int	i = 0;
  int	j = 0;
  int	k = 1;

  while (full_line[i] != NULL)
    i++;
  if (i == 1)
    my_printf("unsetenv: Too few arguments.");
  while (full_line[k] != NULL)
    {
      while (shell->env[j] != NULL)
	{
	  if (str_finder(shell->env[j], full_line[k]) == 0)
	    {
	      remove_one(shell, j);
	      shell->total_env--;
	      break;
	    }
	  j++;
	}
      k++;
      j = 0;
    }
  return (1);
}

