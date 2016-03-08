/*
** init_game.c for init_game in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Feb 24 19:28:55 2016 Arthur ARNAUD
** Last update Tue Mar  8 02:53:38 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	init_game(t_game *game, t_tetri *tetri)
{
  tetri->height = 14;
  tetri->width = 2;
  tetri->x = 0;
  tetri->y = 0;
  if (!(tetri->arr = malloc_tab(tetri->arr, tetri->height, tetri->width))||
      !(game->arr = malloc_tab(game->arr, game->height, game->width)))
    return (1);
  return (0);
}

char	**malloc_tab(char **arr, int height, int width)
{
  int	i;

  if (!(arr = malloc(sizeof(char *) * (height + 1))))
    return (NULL);
  i = -1;
  while (++i < height)
    {
      if (!(arr[i] = malloc(sizeof(char) * width)))
	return (NULL);
      my_memset(arr[i], 0, width);
    }
  arr[i] = NULL;
  return (arr);
}

int            create_all_win(t_window *win, t_game *game)
{
  if (!(win->title = newwin(6, 30, 0, 0)) ||
      !(win->score = create_new_win(10, 25, 8, 4)) ||
      !(win->board = create_new_board(game->height, game->width, 1, 32)))
    return (1);
  return (0);
}
