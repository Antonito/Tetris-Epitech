/*
** add_tetri.c for add_tetri in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 15:41:20 2016 Arthur ARNAUD
** Last update Sat Mar 12 18:25:59 2016 Antoine Baché
*/

#include "tetris.h"

int	check_print_tetri(t_tetri *tetri, t_game *game, int x, int y)
{
  int	i;
  int	j;
  int	tmp;

  i = -1;
  tmp = x;
  while (++i < tetri->height && y < game->height)
    {
      x = tmp;
      j = -1;
      while (++j < tetri->width && x < game->width)
	{
	  if (tetri->arr[i][j] == tetri->color && game->arr[y][x] > -1)
	    return (1);
	  x++;
	}
      y++;
    }
  if (i < tetri->height || j < tetri->width)
    return (1);
  return (0);
}

void	print_tetri(t_tetri *tetri, t_game *game, int x, int y, int move)
{
  int	i;
  int	j;
  int	tmp;

  i = -1;
  tmp = x;
  while (++i < tetri->height)
    {
      x = tmp;
      j = -1;
      while (++j < tetri->width)
	{
	  if (tetri->arr[i][j] == tetri->color)
	    {
	      if (move == VERTICAL_M)
		game->arr[y - 1][x] = -1;
	      else
		game->arr[y][x + move] = -1;
	      game->arr[y][x] = tetri->color;
	    }
	  x++;
	}
      y++;
    }
}

void	clean_tetri(t_tetri *tetri, t_game *game, int x, int y)
{
  int	i;
  int	j;
  int	tmp;

  i = -1;
  tmp = x;
  while (++i < tetri->height)
    {
      x = tmp;
      j = -1;
      while (++j < tetri->width)
	{
	  if (tetri->arr[i][j] == tetri->color)
	    game->arr[y][x] = -1;
	  x++;
	}
      y++;
    }
}

int	add_tetri(t_tetri *tetri, t_game *game)
{
  tetri[game->cur].x = (game->width / 2) - (tetri[game->cur].width / 2) - 1 ;
  tetri[game->cur].y = 1;
  if (check_print_tetri(&tetri[game->cur], game,
			tetri[game->cur].x, tetri[game->cur].y))
    return (check_line(game, tetri));
  print_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  return (0);
}

int     fall_tetri(t_game *game, t_tetri *tetri)
{
  clean_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  if (check_print_tetri(&tetri[game->cur], game,
			tetri[game->cur].x, tetri[game->cur].y + 1))
    return (check_line(game, tetri));
  tetri[game->cur].y += 1;
  print_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  return (0);
}
