/*
** check_args.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 16:35:50 2016 Antoine Baché
** Last update Tue Mar  8 01:51:11 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

char		**set_keys_default(char **keys, char *term)
{
  if (!(keys = malloc(sizeof(char *) * (NB_KEYS + 1))))
    return (NULL);
  keys[NB_KEYS] = NULL;
  if (!(keys[LEFT] = tigetstr("kcub1")) ||
      !(keys[RIGHT] = tigetstr("kcuf1")) ||
      !(keys[TURN] = tigetstr("kcuu1")) ||
      !(keys[DROP] = tigetstr("kcud1")) ||
      !(keys[QUIT] = my_strdup("q")) ||
      !(keys[PAUSE] = my_strdup(" ")))
    return (NULL);
  return (keys);
}

int		init_game_default(t_game *game, char *term)
{
  if (!(game->keys = set_keys_default(game->keys, term)))
    return (1);
  game->level = 1;
  game->next = 0;
  game->lines = 0;
  game->highscore = 0;
  game->score = 0;
  game->time_sec = 0;
  game->time_min = 0;
  game->height = 20;
  game->width = 10;
  game->debug = false;
  game->showNext = true;
  return (0);
}

char		**args_list(void)
{
  char		**tab;

  if (!(tab = malloc(sizeof(char *) * NB_ARGS)) ||
      !(tab[0] = my_strdup("--help")) || !(tab[1] = my_strdup("-l")) ||
      !(tab[2] = my_strdup("--level=")) || !(tab[3] = my_strdup("-kl")) ||
      !(tab[4] = my_strdup("--key-left=")) || !(tab[5] = my_strdup("-kr")) ||
      !(tab[6] = my_strdup("--key-right=")) || !(tab[7] = my_strdup("-kt")) ||
      !(tab[8] = my_strdup("--key-turn=")) || !(tab[9] = my_strdup("-kd")) ||
      !(tab[10] = my_strdup("--key-drop=")) || !(tab[11] = my_strdup("-kq")) ||
      !(tab[12] = my_strdup("--key-quit=")) || !(tab[13] = my_strdup("-kp")) ||
      !(tab[14] = my_strdup("--key-pause=")) ||
      !(tab[15] = my_strdup("--map-size=")) || !(tab[16] = my_strdup("-w")) ||
      !(tab[17] = my_strdup("--without-next")) ||
      !(tab[18] = my_strdup("-d")) || !(tab[19] = my_strdup("--debug")))
    return (NULL);
  return (tab);
}

int		parse_args(int ac, char **av, t_game *game)
{
  ptrtab	array;
  char		**args;
  int		i;
  bool		mode;

  if (!(array = selector()) || !(args = args_list()))
    return (1);
  while (--ac > 0 && av[0] && (i = -1) && (mode = LONG))
    {
      while (++i < NB_ARGS)
	if ((i && !(i & 1) && i < 16) || i == 15)
	  {
	    if (!my_strncmp(args[i], av[0], my_strlen(args[i])))
	      break;
	  }
	else if (my_strncmp(args[i], av[0], my_strlen(args[i]) + 1) == 0)
	  {
	    mode = SHORT;
	    break;
	  }
      if (array[i](game, av, mode))
	return (1);
      av += ((i && i < 15 && mode == SHORT) ? 2 : 1);
    }
  return (free(array), 0);
}

int		check_args(int ac, char **av, char **env)
{
  t_game	game;
  char		*term;

  if (initTerm((term = getTerm((const char **)env)), false) ||
      init_game_default(&game, term))
    return (initTerm(term, true), 1);
  if (ac > 1)
    {
      if (parse_args(ac, av + 1, &game))
	return (initTerm(term, true), 1);
    }
  if (tetris(&game))
    return (initTerm(term, true), 1);
  return (initTerm(term, true), 0);
}
