/*
** check_end.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 12 13:49:18 2016 Antoine Baché
** Last update Tue Mar 15 21:41:22 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	check_end(t_game *game)
{
  if (game->end)
    return (1);
  return (0);
}
