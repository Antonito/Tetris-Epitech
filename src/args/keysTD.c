/*
** keysTD.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:05:44 2016 Antoine Baché
** Last update Mon Mar  7 08:45:34 2016 Antoine Baché
*/

#include "tetris.h"

int	parseKeyTurn(const char *str)
{
  str += 11;
  printf("Key is %s\n", str);
  return (0);
}

int	keyTurnArg(t_game *game, char **av, bool mode)
{
  if (mode == SHORT)
    printf("Key is %s\n", av[1]);
  else if (mode == LONG)
    parseKeyTurn(av[0]);
  return (0);
}

int	parseKeyDrop(const char *str)
{
  str += 11;
  printf("Key is %s\n", str);
  return (0);
}

int	keyDropArg(t_game *game, char **av, bool mode)
{
  if (mode == SHORT)
    printf("Key is %s\n", av[1]);
  else if (mode == LONG)
    parseKeyDrop(av[0]);
  return (0);
}
