/*
** random_tetri.c for random_tetri in /psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 13 23:47:39 2016 Arthur ARNAUD
** Last update Sun Mar 13 23:54:03 2016 Arthur ARNAUD
*/

#include "tetris.h"

int		random_tetri(t_tetri *tetri)
{
  int		i;
  time_t	t;

  i = -1;
  while (tetri[++i].color != -1);
  srand((unsigned) time(&t));
  i = rand() % (i -1);
  return (i);
}
