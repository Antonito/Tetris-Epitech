/*
** game.c for Tetris in /PSU_2015_tetris/src/events
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 02:09:45 2016 Antoine Baché
** Last update Sun Mar 20 15:40:46 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	keyQuitEvent(t_game *game)
{
  (void) game;
  return (2);
}

int	keyPauseEvent(t_game *game)
{
  game->running = ((game->running) ? false : true);
  return (0);
}
