/*
** check_file.c for check_file.c in /psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 14:23:19 2016 Arthur ARNAUD
** Last update Mon Feb 29 14:44:59 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	check_file(char *name)
{
  int	i;

  i = -1;
  while (str[++i] != 0 && str[i] != '.');
  str = str + i;
  if (my_strcmp(str, "tetrimino"))
    return (1);
  return (0);
}
