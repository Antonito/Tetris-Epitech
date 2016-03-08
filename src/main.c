/*
** main.c for main in /home/arnaud_e/rendu/psu/PSU_2015_tetris
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 19:12:02 2016 Arthur ARNAUD
** Last update Tue Mar  8 03:33:25 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

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
  event		events;
  char		buff[BUFF_SIZE];
  int		i;
  int		check;

  if (!(tetri = NULL) && !(events = selectorEvent()))
    return (1);
  while ((i = -1))
    {
      my_memset(buff, 0, BUFF_SIZE);
      if (read(0, buff, BUFF_SIZE - 1) == -1)
	return (free(events), 1);
      while (++i < UNKNOWN)
	if (!my_strncmp(buff, game->keys[i], my_strlen(buff) + 1))
	  {
	    if ((check = (events[i](game, tetri))) == 1)
	      return (free(events), 1);
	    else if (check == 2)
	      return (free(events), 0);
	  }
      usleep(100);
    }
  return (free(events), 0);
}

int		main(int ac, char **av, char **env)
{
  if (!env || check_args(ac, av, env))
    return (1);
  return (0);
}
