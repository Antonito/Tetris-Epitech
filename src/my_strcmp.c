/*
** my_strcmp.c for Tetris in /Prog_Elem/PSU_2015_tetris
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Mar 10 02:52:39 2016 Antoine Baché
** Last update Thu Mar 10 02:52:52 2016 Antoine Baché
*/

#include "tools.h"

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;
  int	j;
  int	t;

  i = 0;
  j = 0;
  t = my_strlen(s1);
  if (t < my_strlen(s2))
    t = my_strlen(s2);
  while (i < t + 1 && !j)
    {
      if (s1[i] != s2[i])
	j = s1[i] - s2[i];
      i = i + 1;
    }
  return (j);
}
