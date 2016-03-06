/*
** main.c for main in /home/arnaud_e/rendu/psu/PSU_2015_tetris
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 19:12:02 2016 Arthur ARNAUD
** Last update Sun Mar  6 15:59:17 2016 Antoine Baché
*/

#include "tetris.h"

int		tetris(void)
{
  t_game	game;
  t_tetri	*tetri;
  t_window	win;
  int		next;
  int		cur;


  if (load_tetri(tetri) || init_game(&game, &next))
      return (1);
  while ((cur = add_tetri(tetri)) != -1)
    {
      while (is_moving(tetri, cur))
	{
	  cur = add_tetri(tetri);
	  fall(tetri, cur);
	  if (display(&win, &next, &game))
	    return (1);
	}
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  if (!env || tetris())
    return (1);
  return (0);
}
