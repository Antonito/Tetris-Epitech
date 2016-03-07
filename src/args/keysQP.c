/*
** keysQP.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:05:44 2016 Antoine Baché
** Last update Mon Mar  7 08:44:56 2016 Antoine Baché
*/

#include "tetris.h"

int	parseKeyQuit(const char *str)
{
  str += 11;
  printf("Key is %s\n", str);
  return (0);
}

int	keyQuitArg(t_game *game, char **av, bool mode)
{
  if (mode == SHORT)
    printf("Key is %s\n", av[1]);
  else if (mode == LONG)
    parseKeyQuit(av[0]);
  return (0);
}

int	parseKeyPause(const char *str)
{
  str += 12;
  printf("Key is %s\n", str);
  return (0);
}

int	keyPauseArg(t_game *game, char **av, bool mode)
{
  if (mode == SHORT)
    printf("Key is %s\n", av[1]);
  else if (mode == LONG)
    parseKeyPause(av[0]);
  return (0);
}
