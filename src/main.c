/*
** main.c for main in /home/arnaud_e/rendu/psu/PSU_2015_tetris
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 19:12:02 2016 Arthur ARNAUD
** Last update Tue Mar  8 04:56:41 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

int		initLoop(t_loop *loop, t_game *game)
{
  if (!(loop->tetri = NULL) && !(loop->next = 0) &&
      (!(loop->events = selectorEvent()) ||
       !(loop->tetri = load_tetri(loop->tetri, game)) ||
       init_game(game, loop->tetri) || init_display(&loop->win, game)))
    return (1);
  return (0);
}

int		checkKeys(t_loop *loop, t_game *game)
{
  if (read(0, loop->buff, BUFF_SIZE - 1) == -1)
    return (free(loop->events), endwin(), 1);
  while (++loop->i < UNKNOWN)
    if (!my_strncmp(loop->buff, game->keys[loop->i],
		    my_strlen(loop->buff) + 1))
      {
	if ((loop->check = (loop->events[loop->i](game, loop->tetri))) == 1)
	  return (free(loop->events), endwin(), 1);
	else if (loop->check == 2)
	  return (free(loop->events), endwin(), 2);
      }
  return (0);
}

int		tetris(t_game *game)
{
  t_loop	loop;

  if (!initLoop(&loop, game))
    while (my_memset(loop.buff, 0, BUFF_SIZE), (loop.i = -1))
      {
	if (display(&loop.win, &loop.tetri[loop.next], game))
	  return (free(loop.events), endwin(), 1);
	if ((loop.check = checkKeys(&loop, game)) == 1)
	  return (1);
	else if(loop.check == 2)
	  return (0);
	usleep(100);
      }
  return (endwin(), 1);
}

int		main(int ac, char **av, char **env)
{
  if (!env || check_args(ac, av, env))
    return (1);
  return (0);
}
