/*
** isOver.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 09:37:13 2016 Antoine Baché
** Last update Sat Mar 12 14:15:23 2016 Antoine Baché
*/

#include "tetris.h"

bool	isOver(t_game *game)
{
  return (check_end(game));
}
