/*
** display.c for display.c in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 22 21:01:23 2016 Arthur ARNAUD
** Last update Mon Feb 29 15:50:27 2016 Arthur ARNAUD
*/

#include "tetris.h"

int		display(t_window *win, t_tetri *next, t_game *game)
{
  initscr();
  noecho();
  curs_set(FALSE);
  start_color();
  init_pair_color();
  if (create_all_win(win, next, game))
    return (1);
  display_interface(win, game);
  display_board(win, next, game);
  endwin();
  return (0);
}
