/*
** display.c for display.c in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 22 21:01:23 2016 Arthur ARNAUD
** Last update Thu Feb 25 17:31:22 2016 Arthur ARNAUD
*/

#include "tetris.h"

void		display(t_window *win, t_tetri *tetri, t_game *game)
{
  initscr();
  noecho();
  curs_set(FALSE);
  start_color();
  init_pair_color();
  if (create_all_win(win, tetri, game))
    return (1);
  while (42)
    {
      display_interface(win, game);
      display_board(win, tetri, game);
    }
  while (42);
  endwin();
}
