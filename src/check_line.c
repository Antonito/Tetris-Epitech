/*
** check_line.c for check_line in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Fri Mar 11 12:13:43 2016 Arthur ARNAUD
** Last update Sat Mar 12 02:09:32 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	check_line(t_game *game, t_tetri *tetri)
{
  int	i;

  i = tetri[game->cur].y - 1;
  while (++i < tetri[game->cur].y + tetri[game->cur].height)
    if (line_full(game, i))
      return (fall_all_tetri(game, i), 1);
  return (1);
}

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
