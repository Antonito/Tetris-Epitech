/*
** board.c for board in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 23:37:45 2016 Arthur ARNAUD
** Last update Wed Feb 24 14:26:11 2016 Arthur ARNAUD
*/

#include "tetris.h"

WINDOW		*create_new_board(int height, int width, int start_y, int start_x)
{
  WINDOW	*win;

  win = newwin(height, width, start_y, start_x);
  wborder(win, '|', '|', '-', '-', '-', '-', '-', '-');
  return (win);
}

void		display_tetriminos(WINDOW *win, char **tab, int height, int width)
{
  int	i;
  int	j;

  i = -1;
  while (++i < height)
    {
      j = -1;
      while(++j < width)
	if (tab[i][j] > 0)
	  {
	    wattrset(win, COLOR_PAIR(tab[i][j]));
	    mvwprintw(win, i, j, "*");
	  }
    }
}

void		display_board(t_tetri *tetri, t_game *game, t_window *win)
{
  display_tetriminos(win->board, game->tab, game->height, game->width);
  mvwprintw(win->next, 2, 0, "Next");
  display_tetriminos(win->next, win->tab, tetri->height, tetri->width);
  wrefresh(board);
  wrefresh(next);
}
