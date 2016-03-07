/*
** debug.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:02:32 2016 Antoine Baché
** Last update Mon Mar  7 07:12:06 2016 Antoine Baché
*/

#include "tetris.h"

int	debugArg(t_game *game, char **av, bool mode)
{
  (void)mode;
  ++av;
  game->debug = true;
  return (0);
}
