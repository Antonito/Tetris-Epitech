/*
** game.c for Tetris in /PSU_2015_tetris/src/events
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 02:09:45 2016 Antoine Baché
** Last update Sun Mar 13 03:45:37 2016 Antoine Baché
*/

#include "tetris.h"

int	keyQuitEvent(t_game *game, t_tetri *tetri)
{
  (void) game;
  (void) tetri;
  return (2);
}

int	keyPauseEvent(t_game *game, t_tetri *tetri)
{
  (void) tetri;
  game->running = ((game->running) ? false : true);
  return (0);
}
