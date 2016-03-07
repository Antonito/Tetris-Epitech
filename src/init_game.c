/*
** init_game.c for init_game in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Feb 24 19:28:55 2016 Arthur ARNAUD
** Last update Mon Mar  7 09:03:12 2016 Antoine Baché
*/

#include "tetris.h"

int	init_game(t_game *game, t_tetri *tetri)
{
  tetri->height = 14;
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
  while (++i < height)
    {
      if (!(tab[i] = malloc(sizeof(char) * width)))
	return (NULL);
      my_memset(tab[i], 0, width);
    }
  tab[i] = NULL;
  return (tab);
}

int            create_all_win(t_window *win, t_tetri *tetri, t_game *game)
{
  if (!(win->title = newwin(6, 30, 0, 0)) ||
      !(win->score = create_new_win(10, 25, 8, 4)) ||
      !(win->board = create_new_board(game->height, game->width, 1, 32)) ||
      !(win->next = create_new_win
  	(tetri->height + 2, tetri->width + 6, 1, game->width + 34)))
    return (1);
  return (0);
}
