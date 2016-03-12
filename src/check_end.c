/*
** check_end.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 12 13:49:18 2016 Antoine Baché
** Last update Sat Mar 12 13:50:11 2016 Antoine Baché
*/

#include "tetris.h"

int	check_end(t_game *game)
{
  int	i;

  i = -1;
  while (++i < game->width)
    {
      if (game->arr[0][i] > -1)
	return (1);
    }
  return (0);
}
