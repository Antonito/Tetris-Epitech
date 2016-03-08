/*
** check_file.c for check_file.c in /psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 14:23:19 2016 Arthur ARNAUD
** Last update Tue Mar  8 16:42:01 2016 Arthur ARNAUD
*/

#include "tetris.h"
#include "tools.h"

int	check_file(char *name)
{
  int	i;

  i = -1;
  while (name[++i] != 0 && name[i] != '.');
  if (my_strncmp(name + i, ".tetrimino", 10))
    return (0);
  return (1);
}
