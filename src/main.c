/*
** main.c for main in /home/arnaud_e/rendu/psu/PSU_2015_tetris
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 19:12:02 2016 Arthur ARNAUD
** Last update Thu Mar 17 23:41:57 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

void		getTime(t_game *game, time_t *start)
{
  time_t	current;

  current = time(NULL) - *start;
  game->time_min = current / 60;
  game->time_sec = current % 60;
}

int		initLoop(t_loop *loop, t_game *game, char *term)
{
  if (!(loop->tetri = NULL) && !(loop->next = 0) &&
      (!(loop->events = selectorEvent()) ||
       !(loop->tetri = load_tetri(loop->tetri, game))))
    return (1);
  if (game->debug && debugMode(game, loop->tetri, term))
    return (1);
  if (init_game(game))
    return (1);
  if (init_display(&loop->win, game, term))
    return (1);
  return (0);
}

int		checkKeys(t_loop *loop, t_game *game)
{
  int		check;

  check = read(0, loop->buff, BUFF_SIZE - 1);
  if (check == -1)
    return (free(loop->events), free2DArray(game->arr), endwin(), 1);
  while (++loop->i < UNKNOWN)
    if (!my_strncmp(loop->buff, game->keys[loop->i],
		    my_strlen(loop->buff) + 1))
      {
	if ((loop->check = (loop->events[loop->i](game))) == 1)
	  return (free(loop->events), free2DArray(game->arr), 1);
	else if (loop->check == 2)
	  return (free(loop->events), free2DArray(game->arr), 2);
      }
  return (0);
}

int		tetris(t_game *game, char *term)
{
  t_loop	loop;
  int		timer;
  time_t	start;

  timer = -1;
  if (!initLoop(&loop, game, term) && (start = time(NULL)) != ((time_t) -1) &&
      !add_tetri(loop.tetri, game) && !(game->end = false))
    while (my_memset(loop.buff, 0, BUFF_SIZE), (loop.i = -1), timer += 2,
	   usleep(100), !check_end(game))
      if (getTime(game, &start),
	  display(&loop.win, &loop.tetri[game->next], game))
	return (freeWin(&loop.win), free(loop.events), freeTetri(loop.tetri),
		endwin(), 1);
      else if ((loop.check = checkKeys(&loop, game)) == 1)
	return (freeWin(&loop.win), freeTetri(loop.tetri), 1);
      else if (loop.check == 2)
	return (freeWin(&loop.win), freeTetri(loop.tetri), 0);
      else if (checkPause(&game->running, game->keys, loop.win.score, &start),
	       timer >= CHECK_TIME)
	if (timer = -1, fall_tetri(game))
	  add_tetri(loop.tetri, game);
  return (1);
}

int		main(int ac, char **av, char **env)
{
  if (!env || check_args(ac, av, env))
    return (1);
  return (0);
}
