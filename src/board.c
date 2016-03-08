/*
** board.c for board in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 23:37:45 2016 Arthur ARNAUD
** Last update Tue Mar  8 03:37:39 2016 Antoine Baché
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
  int	i;
  int	j;

  i = -1;
  while (arr[++i])
    {
      j = -1;
      while (++j < width - 1)
	if (arr[i][j] > 0)
	  {
	    wattrset(win, COLOR_PAIR(arr[i][j]));
	    mvwprintw(win, i, j, "*");
	  }
    }
}

void		display_board(t_window *win, t_tetri *tetri, t_game *game)
{
  display_tetriminos(win->board, game->arr, game->width);
  mvwprintw(win->next, 0, 1, "Next");
  if (!game->next)
    display_tetriminos(win->next, tetri->arr, tetri->width);
  wrefresh(win->board);
  wrefresh(win->next);
}
