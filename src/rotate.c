/*
** rotate.c for rotate in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar 15 12:46:25 2016 Arthur ARNAUD
** Last update Tue Mar 15 13:41:04 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	check_rotate(t_tetri *tetri, t_game *game, int x, int y)
{
  int	i;
  int	j;

  i = -1;
  while (++i < tetri->width && y < tetri->height)
    {
      j = -1;
      while (++j < tetri->height && y < tetri->width)
	{
	  if (game->arr[i][j] > -1 &&
	      tetri->arr[tetri->height - j][i] == tetri->color)
	    return (1);
	  x++;
	}
      y++;
    }
  if (i < tetri->width || i < tetri->height)
    return (1);
  return (0);
}

char	**rotate(t_tetri *tetri)
{
  char	**new_arr;
  int	i;
  int	j;
  int	tmp;

  i = -1;
  if (!(new_arr = malloc(sizeof(char *) * (tetri->width + 1))))
    return (NULL);
  new_arr[tetri->width] = NULL;
  while (++i < tetri->width)
    {
      j = -1;
      if (!(new_arr[i] = malloc(sizeof(char) * (tetri->height))))
	return (NULL);
      while (++j < tetri->height)
	new_arr[i][j] = tetri->arr[tetri->height - j][i];
    }
  tmp = tetri->height;
  tetri->height = tetri->width;
  tetri->width = tmp;
  free(tetri->arr);
  return (new_arr);
}
