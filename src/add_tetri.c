/*
** add_tetri.c for add_tetri in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 15:41:20 2016 Arthur ARNAUD
** Last update Wed Mar 16 00:46:36 2016 Arthur ARNAUD
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

void	print_tetri(t_tetri *tetri, t_game *game, int x, int y)
{
  int	i;
  int	j;
  int	tmp;

  i = 0;
  tmp = x;
  while (i < tetri->height)
    {
      x = tmp;
      j = 0;
      while (j < tetri->width)
	{
	  if (tetri->arr[i][j] == tetri->color)
	    game->arr[y][x] = tetri->color;
	  ++x;
	  ++j;
	}
      ++i;
      ++y;
    }
}

void	clean_tetri(t_tetri *tetri, t_game *game, int x, int y)
{
  int	i;
  int	j;
  int	tmp;

  i = 0;
  tmp = x;
  while (i < tetri->height)
    {
      x = tmp;
      j = 0;
      while (j < tetri->width)
	{
	  if (tetri->arr[i][j] == tetri->color)
	    game->arr[y][x] = -1;
	  ++x;
	  ++j;
	}
      ++i;
      ++y;
    }
}

int	add_tetri(t_tetri *tetri, t_game *game)
{
  game->cur = game->next;
  game->next = random_tetri(tetri);
  copy_tetri(&tetri[game->cur], game);
  game->tetri->x = (game->width / 2) - (game->tetri->width / 2) - 1 ;
  game->tetri->y = 0;
  if (check_print_tetri(game->tetri, game,
			game->tetri->x, game->tetri->y))
    return (check_line(game));
  print_tetri(game->tetri, game, game->tetri->x, game->tetri->y);
  return (0);
}

int     fall_tetri(t_game *game)
{
  clean_tetri(game->tetri, game, game->tetri->x, game->tetri->y);
  if (check_print_tetri(game->tetri, game,
			game->tetri->x, game->tetri->y + 1))
    return (print_tetri(game->tetri, game, game->tetri->x, game->tetri->y),
	    check_line(game));
  game->tetri->y += 1;
  print_tetri(game->tetri, game, game->tetri->x, game->tetri->y);
  return (0);
}
