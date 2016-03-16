/*
** my_strncmp.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 16:22:02 2016 Antoine Baché
** Last update Wed Mar 16 12:13:20 2016 Antoine Baché
*/

#include "tools.h"

int	my_strncmp(const char *s1, const char *s2, int n)
{
  while (n > 0)
    {
      if (*s1 == '\0' || *s1 != *s2)
	return (*s1 - *s2);
      ++s1;
      ++s2;
      --n;
    }
  return (*s1 - *s2);
}
