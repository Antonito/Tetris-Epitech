/*
** keysLR.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:05:44 2016 Antoine Baché
** Last update Mon Mar  7 08:42:42 2016 Antoine Baché
*/

#include "tetris.h"

int	parseKeyLeft(const char *str)
{
  str += 11;
  printf("Key is %s\n", str);
  return (0);
}

int	keyLeftArg(t_game *game, char **av, bool mode)
{
  if (mode == SHORT)
    printf("Key is %s\n", av[1]);
  else if (mode == LONG)
    parseKeyLeft(av[0]);
  return (0);
}

int	parseKeyRight(const char *str)
{
  str += 12;
  printf("Key is %s\n", str);
  return (0);
}

int	keyRightArg(t_game *game, char **av, bool mode)
{
  if (mode == SHORT)
    printf("Key is %s\n", av[1]);
  else if (mode == LONG)
    parseKeyRight(av[0]);
  return (0);
}
