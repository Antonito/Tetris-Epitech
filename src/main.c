/*
** main.c for main in /home/arnaud_e/rendu/psu/PSU_2015_tetris
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 19:12:02 2016 Arthur ARNAUD
** Last update Tue Mar  8 05:54:13 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

void		getTime(t_game *game, time_t *start)
{
  static time_t	current = 0;

  if (game->running)
    current = time(NULL) - *start;
  else
    *start = (int)time(NULL) - (int)*start;
  game->time_min = current / 60;
  game->time_sec = current % 60;
}

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
    return (free(loop->events), free2DArray(game->arr), endwin(), 1);
  while (++loop->i < UNKNOWN)
    if (!my_strncmp(loop->buff, game->keys[loop->i],
		    my_strlen(loop->buff) + 1))
      {
	if ((loop->check = (loop->events[loop->i](game, loop->tetri))) == 1)
	  return (free(loop->events), free2DArray(game->arr), endwin(), 1);
	else if (loop->check == 2)
	  return (free(loop->events), free2DArray(game->arr), endwin(), 2);
      }
  return (0);
}

int		tetris(t_game *game)
{
  t_loop	loop;
  time_t	start;


  if (!initLoop(&loop, game) &&   (start = time(NULL)) != ((time_t) -1))
    while (my_memset(loop.buff, 0, BUFF_SIZE), (loop.i = -1))
      {
	getTime(game, &start);
	if (display(&loop.win, &loop.tetri[loop.next], game))
	  return (free(loop.events), free2DArray(loop.tetri->arr),
		  free(loop.tetri), endwin(), 1);
	if ((loop.check = checkKeys(&loop, game)) == 1)
	  return (free2DArray(loop.tetri->arr), free(loop.tetri), 1);
	else if(loop.check == 2)
	  return (free2DArray(loop.tetri->arr), free(loop.tetri), 0);
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
