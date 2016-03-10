/*
** free.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 03:24:51 2016 Antoine Baché
** Last update Thu Mar 10 12:55:47 2016 Antoine Baché
*/

#include "tetris.h"

void	freeTetri(t_tetri *tetri)
{
  int	i;

  i = 0;
  while (tetri[i].color != -1)
    {
      free(tetri[i].name);
      free2DArray(tetri[i].arr);
      ++i;
    }
  free(tetri);
}

void	freeKeys(char **keys)
{
  free(keys[QUIT]);
  free(keys[PAUSE]);
}

void	free2DArray(char **str)
{
  int	i;

  i = 0;
  while (str && str[i])
    free(str[i++]);
  free(str);
}
