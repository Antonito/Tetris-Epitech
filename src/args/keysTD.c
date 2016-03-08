/*
** keysTD.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:05:44 2016 Antoine Baché
** Last update Tue Mar  8 01:23:15 2016 Antoine Baché
*/

#include "tetris.h"

int	keyTurnArg(t_game *game, char **av, bool mode)
{
  free(game->keys[TURN]);
  if (mode == SHORT)
    {
      if (!(game->keys[TURN] = my_strdup(av[1])))
	return (1);
    }
  else if (mode == LONG)
    {
      if (!(game->keys[TURN] = my_strdup(av[0] + 11)))
	return (1);
    }
  return (0);
}

int	keyDropArg(t_game *game, char **av, bool mode)
{
  free(game->keys[DROP]);
  if (mode == SHORT)
    {
      if (!(game->keys[DROP] = my_strdup(av[1])))
	return (1);
    }
  else if (mode == LONG)
    {
      if (!(game->keys[DROP] = my_strdup(av[0] + 11)))
	return (1);
    }
  return (0);
}
