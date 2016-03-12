/*
** check_end.c for check_end in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Fri Mar 11 12:13:57 2016 Arthur ARNAUD
** Last update Sat Mar 12 01:31:15 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	check_end(t_game *game)
{
  int	i;

  i = -1;
  while (++i < game->width)
    if (game->arr[0][i] > -1)
      return (1);
  return (0);
}
