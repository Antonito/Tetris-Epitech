/*
** main.c for main in /home/arnaud_e/rendu/psu/PSU_2015_tetris
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 19:12:02 2016 Arthur ARNAUD
** Last update Tue Mar  8 00:23:37 2016 Antoine Baché
*/

#include "tetris.h"

/* int		tetris(t_game *game) */
/* { */
/*   t_tetri	*tetri; */
/*   t_window	win; */
/*   int		next; */
/*   int		cur; */


/*   if (load_tetri(tetri) || init_game(game, &next)) */
/*     return (1); */
/*   while ((cur = add_tetri(tetri)) != -1) */
/*     { */
/*       while (is_moving(tetri, cur)) */
/* 	{ */
/* 	  cur = add_tetri(tetri); */
/* 	  fall(tetri, cur); */
/* 	  if (display(&win, &next, game)) */
/* 	    return (1); */
/* 	} */
/*     } */
/*   return (0); */
/* } */

int		tetris(t_game *game)
{
  t_tetri	*tetri;
  t_window	win;
  int		next;

  if (load_tetri(tetri, game) || init_game(game, tetri))
    return (1);
  next = 0;
  if (display(&win, &tetri[next], game))
    return (1);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  if (!env || check_args(ac, av, env))
    return (1);
  return (0);
}
