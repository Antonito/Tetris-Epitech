/*
** init_game.c for init_game in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Feb 24 19:28:55 2016 Arthur ARNAUD
** Last update Mon Mar 14 16:13:15 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	init_game(t_game *game)
{
  if (!(game->arr = malloc_tab(game->arr, game->height, game->width)) ||
      !(game->tetri = malloc(sizeof(t_tetri))))
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
      if (!(arr[i] = malloc(sizeof(char) * width + 1)))
	return (NULL);
      my_memset(arr[i], -1, width + 1);
    }
  arr[height] = NULL;
  return (arr);
}

int            create_all_win(t_window *win, t_game *game)
{
  printf("lil\n");
  win->next = NULL;
  if (!(win->title = newwin(6, 30, 0, 0)) ||
      !(win->score = create_new_win(10, 25, 8, 4)) ||
      !(win->board =
	create_new_board(game->height + 2, game->width + 2, 1, 32)))
    return (1);
  return (0);
}
