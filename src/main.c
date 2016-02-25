/*
** main.c for main in /home/arnaud_e/rendu/psu/PSU_2015_tetris
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 19:12:02 2016 Arthur ARNAUD
** Last update Thu Feb 25 17:29:21 2016 Arthur ARNAUD
*/

#include "tetris.h"

int		tetris(void)
{
  t_game	game;
  t_tetri	tetri;
  t_window	win;

  if (init_game(&game, &tetri))
      return (1);
  if (display(&win, &tetri, &game))
    return (1);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  if (!env || tetris())
    return (1);
  return (0);
}
