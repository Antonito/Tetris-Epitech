/*
** add_tetri.c for add_tetri in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 15:41:20 2016 Arthur ARNAUD
** Last update Thu Mar 10 07:12:14 2016 Antoine Baché
*/

#include "tetris.h"

int	check_print_tetri(t_tetri *tetri, t_game *game, int x, int y)
{
  while (y++ < tetri->y + tetri->height && y < game->height)
    {
      while (x++ < tetri->x + tetri->width && x < game->width)
	if (tetri->arr[y - tetri->y][x - tetri->x] > 0 &&
	    game->arr[y][x] > 0)
	  return (1);
    }
  return (0);
}

void	print_tetri(t_tetri *tetri, t_game *game, int x, int y)
{
  while (y++ < tetri->y + tetri->height && y < game->height)
    {
      while (x++ < tetri->x + tetri->width && x < game->width)
	if (tetri->arr[y - tetri->y][x - tetri->x] > 0)
	  game->arr[y][x] = tetri->color;
    }
}

void	clean_tetri(t_tetri *tetri, t_game *game, int x, int y)
{
  while (y++ < tetri->y + tetri->height && y < game->height)
    {
      while (x++ < tetri->x + tetri->width && x < game->width)
	if (tetri->arr[y - tetri->y][x - tetri->x] > 0)
	  game->arr[y][x] = 0;
    }
}

int	add_tetri(t_tetri *tetri, t_game *game)
{
  static int	i = 0;

  i++;
  tetri[game->cur].x = (game->width / 2) - (tetri[game->cur].width / 2) ;
  tetri[game->cur].y = 0;
  if (check_print_tetri(&tetri[game->cur], game,
			tetri[game->cur].x, tetri[game->cur].y))
    return (1);
  print_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  printf("%d\n", i);
  return (0);
}

int     fall_tetri(t_game *game, t_tetri *tetri)
{
  clean_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  if (check_print_tetri(&tetri[game->cur], game,
			tetri[game->cur].x, tetri[game->cur].y + 1))
    return (1);
  tetri[game->cur].y += 1;
  print_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  return (0);
}
