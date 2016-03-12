/*
** display.c for display.c in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 22 21:01:23 2016 Arthur ARNAUD
** Last update Sat Mar 12 13:40:40 2016 Antoine Baché
*/

#include "tetris.h"

int		init_display(t_window *win, t_game *game, char *term)
{
  if (!(initscr()))
    return (error("Cannot start new term\n"));
  if (initTerm(term, false))
    return (error("Cannot init term\n"));
  printf("display.c : init display before curs_set(FALSE)\n");
  curs_set(0);
  printf("display.c : init display after curs_set(FALSE)\n");
  start_color();
  init_pair_color();
  if (create_all_win(win, game))
    return (error("Cannot create windows\n"));
  return (0);
}

int		display(t_window *win, t_tetri *next, t_game *game)
{
  if (win->next)
    delwin(win->next);
  if (!(win->next =
	create_new_win(next->height + 2, next->width + 6, 1, game->width + 36)))
    return (1);
  display_interface(win, game);
  display_board(win, next, game);
  return (0);
}
