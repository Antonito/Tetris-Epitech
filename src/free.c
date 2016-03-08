/*
** free.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 03:24:51 2016 Antoine Baché
** Last update Tue Mar  8 03:26:38 2016 Antoine Baché
*/

#include <stdlib.h>

void	free2DArray(char **str)
{
  int	i;

  i = 0;
  while (str[i])
    free(str[i++]);
  free(str);
}
