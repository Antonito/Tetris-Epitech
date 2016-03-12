/*
** isOver.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 09:37:13 2016 Antoine Baché
** Last update Sat Mar 12 13:45:30 2016 Antoine Baché
*/

#include "tetris.h"

bool	isOver(t_game *game)
{
  /*
  ** Si tetrimino touche haut plateau, return true;
  */
  return (check_end(game));
}
