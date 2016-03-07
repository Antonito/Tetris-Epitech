/*
** level.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:02:32 2016 Antoine Baché
** Last update Mon Mar  7 07:51:55 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

int	parseLevel(const char *str)
{
  str += 7;
  return (my_getnbr(str));
}

int	levelArg(t_game *game, char **av, bool mode)
{
  int	value;

  if (mode == SHORT)
    value = ((av[1]) ? my_getnbr(av[1]) : -1);
  else if (mode == LONG)
    value = parseLevel(av[0]);
  printf("Size = %d\n", value);
  return (0);
}
