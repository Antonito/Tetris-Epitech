/*
** add_tetri.c for add_tetri in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 15:41:20 2016 Arthur ARNAUD
** Last update Wed Mar  9 02:51:28 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	check_print_tetri(t_tetri *tetri, t_game *game)
{
  int	i;
  int	j;

  i = y;
  while (i++ < tetri->y + tetri->height && i < game->height)
    {
      j = x;
      while (j++ < tetri->x + tetri->width && j < game->width)
	if (tetri->arr[i - tetri->y][j - tetri->x] > 0 &&
	    game->arr[i][j] > 0)
	  return (1);
    }
}

int	print_tetri(t_tetri *tetri, t_game *game)
{
  int	i;
  int	j;

  i = y;
  while (i++ < tetri->y + tetri->height)
    {
      j = x;
      while (j++ < tetri->x + tetri->width)
	if (tetri->arr[i - tetri->y][j - tetri->x] > 0)

    }
}

int	add_tetri(t_tetri *tetri, t_game *game, int cur)
{
  tetri[cur].x = (game->width / 2) - (tetri[cur].width / 2) ;
  tetri[cur].y = 0;
  if (check_print_tetri(tetri[cur], game) ||
      print_tetri(tetri[cur], game))
    return (1);
  return (0);
}
