/*
** display.c for display.c in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 22 21:01:23 2016 Arthur ARNAUD
** Last update Tue Mar  8 02:18:13 2016 Arthur ARNAUD
*/

#include "tetris.h"

int		init_display(t_window *win, t_game *game)
{
  initscr();
  noecho();
  curs_set(FALSE);
  start_color();
  init_pair_color();
  if (create_all_win(win, game))
    return (1);
  return (0);
}

int		display(t_window *win, t_tetri *next, t_game *game)
{
  if (!(win->next =
	create_new_win(next->height + 2, next->width + 6, 1, game->width + 34)))
    return (1);
  display_interface(win, game);
  display_board(win, next, game);
  return (0);
}
