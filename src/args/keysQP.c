/*
** keysQP.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:05:44 2016 Antoine Baché
** Last update Tue Mar  8 01:22:41 2016 Antoine Baché
*/

#include "tetris.h"

int	keyQuitArg(t_game *game, char **av, bool mode)
{
  free(game->keys[QUIT]);
  if (mode == SHORT)
    {
      if (!(game->keys[QUIT] = my_strdup(av[1])))
	return (1);
    }
  else if (mode == LONG)
    {
      if (!(game->keys[QUIT] = my_strdup(av[0] + 11)))
	return (1);
    }
  return (0);
}

int	keyPauseArg(t_game *game, char **av, bool mode)
{
  free(game->keys[PAUSE]);
  if (mode == SHORT)
    {
      if (!(game->keys[PAUSE] = my_strdup(av[1])))
	return (1);
    }
  else if (mode == LONG)
    {
      if (!(game->keys[PAUSE] = my_strdup(av[0] + 12)))
	return (1);
    }
  return (0);
}
