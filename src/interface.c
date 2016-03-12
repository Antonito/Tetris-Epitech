/*
** interface.c for interface in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 14:52:36 2016 Arthur ARNAUD
** Last update Fri Mar 11 18:15:09 2016 Arthur ARNAUD
*/

#include "tetris.h"

WINDOW		*create_new_win(int height, int width, int start_y, int start_x)
{
  WINDOW	*win;

  if (!(win = newwin(height, width, start_y, start_x)))
    return (NULL);
  wborder(win, '|', '|', '-', '-', '/', '\\', '\\', '/');
  return (win);
}

void		init_pair_color()
{
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void		display_title_(WINDOW *win)
{
  wattrset(win, COLOR_PAIR(2));
  mvwprintw(win, 1, 16, "***");
  mvwprintw(win, 2, 16, "* *");
  mvwprintw(win, 3, 16, "** ");
  mvwprintw(win, 4, 16, "* *");
  mvwprintw(win, 5, 16, "* *");
  wattrset(win, COLOR_PAIR(6));
  mvwprintw(win, 1, 20, " * ");
  mvwprintw(win, 2, 20, "   ");
  mvwprintw(win, 3, 20, " * ");
  mvwprintw(win, 4, 20, " * ");
  mvwprintw(win, 5, 20, " * ");
  wattrset(win, COLOR_PAIR(5));
  mvwprintw(win, 1, 24, "***");
  mvwprintw(win, 2, 24, "*  ");
  mvwprintw(win, 3, 24, "***");
  mvwprintw(win, 4, 24, "  *");
  mvwprintw(win, 5, 24, "***");
}

void		display_title(WINDOW *win)
{
  wattrset(win, COLOR_PAIR(1));
  mvwprintw(win, 1, 4, "***");
  mvwprintw(win, 2, 4, " * ");
  mvwprintw(win, 3, 4, " * ");
  mvwprintw(win, 4, 4, " * ");
  mvwprintw(win, 5, 4, " * ");
  wattrset(win, COLOR_PAIR(4));
  mvwprintw(win, 1, 8, "***");
  mvwprintw(win, 2, 8, "*  ");
  mvwprintw(win, 3, 8, "***");
  mvwprintw(win, 4, 8, "*  ");
  mvwprintw(win, 5, 8, "***");
  wattrset(win, COLOR_PAIR(3));
  mvwprintw(win, 1, 12, "***");
  mvwprintw(win, 2, 12, " * ");
  mvwprintw(win, 3, 12, " * ");
  mvwprintw(win, 4, 12, " * ");
  mvwprintw(win, 5, 12, " * ");
  display_title_(win);
}

void		display_interface(t_window *win, t_game *game)
{
  display_score(win->score, game);
  wborder(win->score, '|', '|', '-', '-', '/', '\\', '\\', '/');
  display_title(win->title);
  wrefresh(win->title);
  wrefresh(win->score);
}
