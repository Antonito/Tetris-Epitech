/*
** next.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:02:32 2016 Antoine Baché
** Last update Mon Mar 14 18:52:44 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	nextArg(t_game *game, char **av, bool mode)
{
  (void)mode;
  (void)av;
  game->showNext = false;
  return (0);
}
