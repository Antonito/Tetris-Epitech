/*
** game.c for Tetris in /PSU_2015_tetris/src/events
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 02:09:45 2016 Antoine Baché
** Last update Wed Mar  9 09:59:44 2016 Antoine Baché
*/

#include "tetris.h"

int	keyQuitEvent(t_game *game, t_tetri *tetri)
{
  printf("Quit!\n");
  return (2);
}

int	keyPauseEvent(t_game *game, t_tetri *tetri)
{
  game->running = ((game->running) ? false : true);
  return (0);
}
