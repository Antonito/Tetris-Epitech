/*
1;4204;0c** check_args.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 16:35:50 2016 Antoine Baché
** Last update Mon Mar  7 08:00:24 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

void		init_game_default(t_game *game)
{
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
      printf("i = %d\n", i);
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
