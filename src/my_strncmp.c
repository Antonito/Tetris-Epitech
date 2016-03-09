/*
** my_strncmp.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 16:22:02 2016 Antoine Baché
** Last update Wed Mar  9 02:49:14 2016 Antoine Baché
*/

#include "tools.h"

int	my_strncmp(const char *s1, const char *s2, int n)
{
  int	i;

  i = 0;
  if (!s1[i])
    return (-1);
  while (i <= n)
    {
      if (s1[i] && s1[i] != s2[i])
	return (s1[i] - s2[i]);
      else if (s1[i] == '\0')
	return (0);
      ++i;
    }
  return (-1);
}
