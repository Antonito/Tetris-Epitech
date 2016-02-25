/*
** main.c for main in /home/arnaud_e/rendu/psu/PSU_2015_tetris
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 19:12:02 2016 Arthur ARNAUD
** Last update Thu Feb 25 19:41:23 2016 Arthur ARNAUD
*/

#include "tetris.h"

int		tetris(void)
{
  t_game	game;
  t_tetri	*tetri;
  t_tetri	next;
  t_window	win;


  if (load_tetri(tetri) || init_game(&game, &next))
      return (1);
  if (display(&win, &next, &game))
    return (1);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  if (!env || tetris())
    return (1);
  return (0);
}
