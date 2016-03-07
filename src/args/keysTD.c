/*
** keysTD.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:05:44 2016 Antoine Baché
** Last update Mon Mar  7 10:08:10 2016 Antoine Baché
*/

#include "tetris.h"

int	parseKeyTurn(const char *str, int *key)
{
  str += 11;
  getKey(key, str);
  return (0);
}

int	keyTurnArg(t_game *game, char **av, bool mode)
{
  if (mode == SHORT)
    getKey(&game->keys.turn, av[1]);
  else if (mode == LONG)
    parseKeyTurn(av[0], &game->keys.turn);
  return (0);
}

int	parseKeyDrop(const char *str, int *key)
{
  str += 11;
  getKey(key, str);
  return (0);
}

int	keyDropArg(t_game *game, char **av, bool mode)
{
  if (mode == SHORT)
    getKey(&game->keys.drop, av[1]);
  else if (mode == LONG)
    parseKeyDrop(av[0], &game->keys.drop);
  return (0);
}
