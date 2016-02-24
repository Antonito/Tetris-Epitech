/*
** display.c for display.c in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 22 21:01:23 2016 Arthur ARNAUD
** Last update Wed Feb 24 14:08:32 2016 Arthur ARNAUD
*/

#include "tetris.h"

void		create_all_win(t_window *win, t_tetri *tetri, t_game *game)
{
  win->title = newwin(6, 30, 0, 0);
  win->score = create_new_win(10, 25, 8, 4);
  win->board =
    create_new_board(game->height, game->width, 15, 2);
  win->next =
    create_new_win(tetri->height + 2, tetri->width + 2, game->width + 20, 2);
}

void		display(t_tetri *tetri, t_game *game)
{
  t_window	*win;

  initscr();
  noecho();
  curs_set(FALSE);
  create_all_win(win, tetri, game);
  start_color();
  init_pair_color();
  while (42)
    {
      display_interface(win, tetri, game);
      display_interface(win, tetri, game);
    }
  endwin();
}
