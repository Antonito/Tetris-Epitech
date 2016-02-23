/*
** display.c for display.c in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 22 21:01:23 2016 Arthur ARNAUD
** Last update Tue Feb 23 13:42:54 2016 Arthur ARNAUD
*/

#include <ncurses.h>

WINDOW		*create_new_win(int height, int width, int start_y, int start_x)
{
  WINDOW	*win;

  win = newwin(height, width, start_y, start_x);
  wborder(win, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wrefresh(win);
  return (win);
}

int		display_title(WINDOW *win)
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

  wattrset(win, COLOR_PAIR(2));

  mvwprintw(win, 1, 16, "***");
  mvwprintw(win, 2, 16, "* *");
  mvwprintw(win, 3, 16, "**  ");
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

int	refresh_win(WINDOW *score, WINDOW *board, WINDOW *title, WINDOW *tetrinimo)
{
  wrefresh(board);
  wrefresh(title);
  wrefresh(score);
  wrefresh(tetrinimo);
}

void		init_pair_color()
{
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

int		display()
{
  WINDOW	*title;
  WINDOW	*score;
  WINDOW	*board;
  WINDOW	*tetrinimo;
  int		row;
  int		col;

  initscr();
  noecho();
  curs_set(FALSE);
  start_color();
  init_pair_color();
  title = newwin(6, 30, 0, 0);
  score = create_new_win(10, 25, 8, 4);
  board = create_new_win(25, 15, 0, 32);
  tetrinimo = create_new_win(5, 10, 0, 52);
  while (42)
    {
      refresh_win(score, board, title, tetrinimo);
      display_title(title);
    }
  endwin();
}

int	main()
{
  display();
}
