/*
** copy_tetri.c for copy_tetri in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Mar 14 01:25:25 2016 Arthur ARNAUD
** Last update Mon Mar 14 15:31:15 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	copy_tetri(t_tetri *tetri, t_game *game)
{
  int	i;
  int	j;

  i = -1;
  game->tetri->width = tetri->width;
  game->tetri->height = tetri->height;
  game->tetri->x = tetri->x;
  game->tetri->y = tetri->y;
  game->tetri->color = tetri->color;
  game->tetri->name = NULL;
  game->tetri->error = false;
  if (!(game->tetri->arr = malloc(sizeof(char *) * (game->tetri->height + 1))))
    return (1);
  game->tetri->arr[game->tetri->height] = NULL;
  while (++i < game->tetri->height)
    {
      if (!(game->tetri->arr[i] = malloc(sizeof(char) * game->tetri->width)))
	return (1);
      j = -1;
      while (++j < game->tetri->width)
	game->tetri->arr[i][j] = tetri->arr[i][j];
    }
  return (0);
}
