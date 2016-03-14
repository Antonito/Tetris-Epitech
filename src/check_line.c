/*
** check_line.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 12 13:50:50 2016 Antoine Baché
** Last update Mon Mar 14 14:35:59 2016 Arthur ARNAUD
*/

#include "tetris.h"

void	fall_all_tetri(t_game *game, int index)
{
  int	i;

  while ((i = -1) && index > 1)
    {
      while (++i < game->width)
	game->arr[index][i] = game->arr[index - 1][i];
      --index;
    }
  while (++i < game->width)
    game->arr[0][i] = -1;
}

int	line_full(t_game *game, int index)
{
  int	i;

  i = -1;
  while (++i < game->width)
    if (game->arr[index][i] < 0)
      return (0);
  i = -1;
  while (++i < game->width)
    game->arr[index][i] = -1;
  return (1);
}

int	check_line(t_game *game)
{
  int	i;

  i = game->tetri->y - 1;
  while (++i < game->tetri->y + game->tetri->height)
    if (line_full(game, i))
      return (fall_all_tetri(game, i), 1);
  return (1);
}
