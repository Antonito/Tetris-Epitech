/*
** main.c for main in /home/arnaud_e/rendu/psu/PSU_2015_tetris
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 19:12:02 2016 Arthur ARNAUD
** Last update Tue Mar  8 02:39:26 2016 Arthur ARNAUD
*/

#include "tetris.h"

int		tetris(t_game *game)
{
  t_tetri	*tetri;
  t_window	win;
  int		next;
  int		cur;

  tetri = NULL;
  if (!(tetri = load_tetri(tetri, game)) || init_game(game, tetri) ||
      init_display(&win, game))
    return (1);
  next = 0;
  while (42)
    if (display(&win, &tetri[next], game))
      return (1);
  /* while ((cur = add_tetri(tetri, game))) */
  /*   { */
  /*     next = set_next(tetri); */
  /*     while (is_moving(tetri, cur)) */
  /* 	{ */
  /* 	  if (check_line_full(game)) */
  /* 	    board_fall(game); */
  /* 	  move_tetri(tetri, game); */
  /* 	  if (display(&win, &tetri[next], game)) */
  /* 	    return (1); */
  /* 	} */
  /* } */
  endwin();
  return (0);
}

int		main(int ac, char **av, char **env)
{
  if (!env || check_args(ac, av))
    return (1);
  return (0);
}
