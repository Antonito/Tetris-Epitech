/*
** check_args.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 16:35:50 2016 Antoine Baché
** Last update Tue Mar  8 02:58:37 2016 Arthur ARNAUD
*/

#include "tetris.h"
#include "tools.h"

void		set_keys_default(t_key *keys)
{
  keys->left = KEY_LEFT;
  keys->right = KEY_RIGHT;
  keys->turn = KEY_UP;
  keys->drop = KEY_DOWN;
  keys->quit = 'q';
  keys->pause = ' ';
}

void		init_game_default(t_game *game)
{
  set_keys_default(&game->keys);
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
}

char		**args_list(void)
{
  char		**arr;

  if (!(arr = malloc(sizeof(char *) * NB_ARGS)) ||
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
	return (1);
      av += ((i && i < 15 && mode == SHORT) ? 2 : 1);
    }
  return (free(array), 0);
}

int		check_args(int ac, char **av)
{
  t_game	game;

  init_game_default(&game);
  if (ac > 1)
    {
      if (parse_args(ac, av + 1, &game))
	return (1);
    }
  if (tetris(&game))
    return (1);
  return (0);
}
