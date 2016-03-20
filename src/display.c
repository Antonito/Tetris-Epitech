/*
** display.c for display.c in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 22 21:01:23 2016 Arthur ARNAUD
** Last update Sun Mar 20 16:06:17 2016 Arthur ARNAUD
*/

#include "tetris.h"

int		init_display(t_window *win, t_game *game, char *term)
{
  if (!(initscr()))
    return (error("Cannot start new term\n"));
  if (initTerm(term, false))
    return (error("Cannot init term\n"));
  curs_set(0);
  start_color();
  init_pair_color();
  if (create_all_win(win, game))
    return (error("Cannot create windows\n"));
  return (0);
}

int		display(t_window *win, t_tetri *next, t_game *game)
{
  int		cols;
  int		line;

  cols = 0;
  line = 0;
  if (win->next)
    {
      wclear(win->next);
      werase(win->next);
      wrefresh(win->next);
      delwin(win->next);
    }
  getmaxyx(stdscr, line, cols);
  if ((game->width + next->width + 40) > cols || game->height > line)
    return (error("Window too small"));
  if (!(win->next =
	create_new_win(next->height + 2, next->width + 4, 1, game->width + 36)))
    return (error("Cannot create window\n"));
  display_interface(win, game);
  werase(win->board);
  wattrset(win->board, COLOR_PAIR(7));
  wborder(win->board, '|', '|', '-', '-', '-', '-', '-', '-');
  display_board(win, next, game);
  return (0);
}
