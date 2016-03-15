/*
** board.c for board in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 23:37:45 2016 Arthur ARNAUD
** Last update Mon Mar 14 19:22:53 2016 Arthur ARNAUD
*/

#include "tetris.h"

WINDOW		*create_new_board(int height, int width, int start_y,
				  int start_x)
{
  WINDOW	*win;

  if (!(win = newwin(height, width, start_y, start_x)))
    return (NULL);
  wborder(win, '|', '|', '-', '-', '-', '-', '-', '-');
  return (win);
}

void		display_tetriminos(WINDOW *win, char **arr, int width)
{
  int		i;
  int		j;

  i = -1;
  while (arr[++i])
    {
      j = -1;
      while (++j < width)
	if (arr[i][j] > -1)
	  {
	    wattrset(win, COLOR_PAIR(arr[i][j]));
	    mvwprintw(win, i + 1, j + 1, "*");
	  }
    }
}

void		display_next(WINDOW *win, char **arr, int width, int color)
{
  int		i;
  int		j;

  i = -1;
  while (arr[++i])
    {
      j = -1;
      while (++j < width)
	if (arr[i][j] == color)
	  {
	    wattrset(win, COLOR_PAIR(arr[i][j]));
	    mvwprintw(win, i + 1, j + 1, "*");
	  }
    }
}

void		display_board(t_window *win, t_tetri *tetri, t_game *game)
{
  display_tetriminos(win->board, game->arr, game->width);
  mvwprintw(win->next, 0, 1, "Next");
  if (game->showNext)
    display_next(win->next, tetri->arr, tetri->width, tetri->color);
  wrefresh(win->board);
  wrefresh(win->next);
}
