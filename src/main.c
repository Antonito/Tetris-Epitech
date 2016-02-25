/*
** main.c for main in /home/arnaud_e/rendu/psu/PSU_2015_tetris
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 19:12:02 2016 Arthur ARNAUD
** Last update Wed Feb 24 20:24:44 2016 Arthur ARNAUD
*/

#include "tetris.h"

int		main()
{
  t_game	game;
  t_tetri	tetri;
  t_window	win;

  init_game(&game, &tetri);
  create_all_win(&win, &tetri, &game);
  display(&win, &tetri, &game);
  return (0);
}
