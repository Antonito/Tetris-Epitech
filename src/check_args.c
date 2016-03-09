/*
** check_args.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 16:35:50 2016 Antoine Baché
** Last update Wed Mar  9 11:19:20 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

char		**set_keys_default(char **keys)
{
  int		i;

  if (setupterm(NULL, 0, &i) < 0 ||
      !(keys = malloc(sizeof(char *) * (NB_KEYS + 1))))
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

int		init_game_default(t_game *game)
{
  if (!(game->keys = set_keys_default(game->keys)))
    return (error("Cannot malloc\n"));
  game->level = 1;
  game->next = 0;
  game->line = 0;
  game->highscore = 0;
  game->score = 0;
  game->time_sec = 0;
  game->time_min = 0;
  game->height = 20;
  game->width = 10;
  game->debug = false;
  game->showNext = true;
  game->running = true;
  return (0);
}

char		**args_list(void)
{
  char		**arr;

  if (!(arr = malloc(sizeof(char *) * (NB_ARGS + 1))) ||
      !(arr[0] = my_strdup("--help")) || !(arr[1] = my_strdup("-l")) ||
      !(arr[2] = my_strdup("--level=")) || !(arr[3] = my_strdup("-kl")) ||
      !(arr[4] = my_strdup("--key-left=")) || !(arr[5] = my_strdup("-kr")) ||
      !(arr[6] = my_strdup("--key-right=")) || !(arr[7] = my_strdup("-kt")) ||
      !(arr[8] = my_strdup("--key-turn=")) || !(arr[9] = my_strdup("-kd")) ||
      !(arr[10] = my_strdup("--key-drop=")) || !(arr[11] = my_strdup("-kq")) ||
      !(arr[12] = my_strdup("--key-quit=")) || !(arr[13] = my_strdup("-kp")) ||
      !(arr[14] = my_strdup("--key-pause=")) ||
      !(arr[15] = my_strdup("--map-size=")) || !(arr[16] = my_strdup("-w")) ||
      !(arr[17] = my_strdup("--without-next")) ||
      !(arr[18] = my_strdup("-d")) || !(arr[19] = my_strdup("--debug")))
    return (NULL);
  arr[20] = NULL;
  return (arr);
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
	return (free(array), free2DArray(args), 1);
      av += ((i && i < 15 && mode == SHORT) ? 2 : 1);
    }
  return (free(array), free2DArray(args), 0);
}

int		check_args(int ac, char **av, char **env)
{
  t_game	game;
  char		*term;
  char		*smkx;

  if (init_game_default(&game))
    return (error("Cannot initialise game\n"));
  if (!(term = getTerm((const char **)env)))
    return (freeKeys(game.keys), error("Cannot find info about term\n"));
  if (ac > 1)
    {
      initTerm(term, false);
      if (parse_args(ac, av + 1, &game))
	return (initTerm(term, true), freeKeys(game.keys), 1);
      initTerm(term, true);
    }
  if (!(smkx = tigetstr("smkx")) || putp(smkx) == ERR)
    return (freeKeys(game.keys), 1);
  if (tetris(&game, term))
    return (initTerm(term, true), freeKeys(game.keys), endwin(), 1);
  return (initTerm(term, true), freeKeys(game.keys), endwin(), 0);
}
