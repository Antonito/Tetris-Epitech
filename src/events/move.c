/*
** move.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/events
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 02:06:28 2016 Antoine Baché
** Last update Tue Mar 15 13:38:45 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	keyLeftEvent(t_game *game)
{
  clean_tetri(game->tetri, game, game->tetri->x, game->tetri->x);
  if (check_print_tetri(game->tetri, game,
			game->tetri->x - 1, game->tetri->y))
    return (0);
  game->tetri->x -= 1;
  print_tetri(game->tetri, game, game->tetri->x, game->tetri->y);
  return (0);
}

int	keyRightEvent(t_game *game)
{
  clean_tetri(game->tetri, game, game->tetri->x, game->tetri->y);
  if (check_print_tetri(game->tetri, game, game->tetri->x + 1, game->tetri->y))
    return (0);
  game->tetri->x += 1;
  print_tetri(game->tetri, game, game->tetri->x, game->tetri->y);
  return (0);
}

int	keyTurnEvent(t_game *game)
{
  clean_tetri(game->tetri, game, game->tetri->x, game->tetri->y);
  if (!check_rotate(game->tetri, game, game->tetri->x, game->tetri->y))
    if (!(game->tetri->arr = rotate(game->tetri)))
      return (1);
  print_tetri(game->tetri, game, game->tetri->x, game->tetri->y);
  return (0);
}

int	keyDropEvent(t_game *game)
{
  int	i;

  i = 0;
  clean_tetri(game->tetri, game, game->tetri->x, game->tetri->y);
  while (check_print_tetri(game->tetri, game,
			   game->tetri->x, game->tetri->y + i))
    i++;
  game->tetri->y += i;
  print_tetri(game->tetri, game, game->tetri->x, game->tetri->y);
  return (0);
}
