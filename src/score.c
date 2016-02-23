/*
** score.c for score in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 13:43:38 2016 Arthur ARNAUD
** Last update Tue Feb 23 14:05:42 2016 Arthur ARNAUD
*/

#include "score.h"

WINDOW		*create_new_win(int height, int width, int start_y, int start_x)
{
  WINDOW	*win;

  win = newwin(height, width, start_y, start_x);
  wborder(win, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wrefresh(win);
  return (win);
}

int		refresh_win(WINDOW *score,
			    WINDOW *board,
			    WINDOW *title,
			    WINDOW *tetrinimo)
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

int		display_interface()
{
  WINDOW	*title;
  WINDOW	*score;
  int		row;
  int		col;

  start_color();
  init_pair_color();
  title = newwin(6, 30, 0, 0);
  score = create_new_win(10, 25, 8, 4);
  display_score(score);
  display_title(title);
  refresh_win(score, board, title, tetrinimo);
}
