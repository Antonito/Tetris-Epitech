/*
** keysQP.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:05:44 2016 Antoine Baché
** Last update Mon Mar  7 10:07:57 2016 Antoine Baché
*/

#include "tetris.h"

int	parseKeyQuit(const char *str, int *key)
{
  str += 11;
  getKey(key, str);
  return (0);
}

int	keyQuitArg(t_game *game, char **av, bool mode)
{
  if (mode == SHORT)
    getKey(&game->keys.quit, av[1]);
  else if (mode == LONG)
    parseKeyQuit(av[0], &game->keys.quit);
  return (0);
}

int	parseKeyPause(const char *str, int *key)
{
  str += 12;
  getKey(key, str);
  return (0);
}

int	keyPauseArg(t_game *game, char **av, bool mode)
{
  if (mode == SHORT)
    getKey(&game->keys.pause, av[1]);
  else if (mode == LONG)
    parseKeyPause(av[0], &game->keys.pause);
  return (0);
}
