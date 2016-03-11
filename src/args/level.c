/*
** level.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:02:32 2016 Antoine Baché
** Last update Fri Mar 11 03:40:53 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

int	parseLevel(const char *str)
{
  str += 8;
  return (my_getnbr(str));
}

int	levelArg(t_game *game, char **av, bool mode)
{
  int	value;

  if (mode == SHORT && av[1])
    value = ((av[1]) ? my_getnbr(av[1]) : 0);
  else if (mode == LONG && my_strlen(av[0]) > 8)
    value = parseLevel(av[0]);
  else
    return (1);
  if (value)
    game->level = value;
  else
    {
      write(2, "Incorrect level\n", 16);
      return (1);
    }
  return (0);
}
