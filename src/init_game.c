/*
** init_game.c for init_game in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Feb 24 19:28:55 2016 Arthur ARNAUD
** Last update Thu Feb 25 13:19:48 2016 Antoine Baché
*/

#include "tetris.h"

int	init_game(t_game *game, t_tetri *tetri)
{
  game->level = 1;
  game->next = 0;
  game->lines = 0;
  game->highscore = 0;
  game->time_sec = 0;
  game->time_min = 0;
  game->height = 20;
  game->width = 10;
  tetri->height = 2;
  tetri->width = 2;
  tetri->x = 0;
  tetri->y = 0;
  if (!(tetri->tab = malloc_tab(tetri->tab, tetri->height, tetri->width))||
      !(game->tab = malloc_tab(game->tab, game->height, game->width)))
    return (1);
  return (0);
}

char	**malloc_tab(char **tab, int height, int width)
{
  int	i;

  if (!(tab = malloc(sizeof(char *) * (height + 1))))
    return (NULL);
  i = -1;
  while(++i < height)
    {
      if (!(tab[i] = malloc(sizeof(char) * width)))
	return (NULL);
      my_memset(tab[i], 0, width);
    }
  tab[i] = NULL;
  return (tab);
}

void            create_all_win(t_window *win, t_tetri *tetri, t_game *game)
{
  win->title = newwin(6, 30, 0, 0);
  win->score = create_new_win(10, 25, 8, 4);
  win->board =
    create_new_board(game->height, game->width, 15, 2);
  win->next =
    create_new_win(tetri->height + 2, tetri->width + 2, game->width + 20, 2);
}
