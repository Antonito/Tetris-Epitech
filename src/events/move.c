/*
** move.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/events
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 02:06:28 2016 Antoine Baché
** Last update Wed Mar  9 06:14:10 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	keyLeftEvent(t_game *game, t_tetri *tetri)
{
  clean_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  if (check_print_tetri(&tetri[game->cur], game,
			tetri[game->cur].x - 1, tetri[game->cur].y))
    return (0);
  tetri[game->cur].x -= 1;
  print_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  return (0);
}

int	keyRightEvent(t_game *game, t_tetri *tetri)
{
  clean_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  if (check_print_tetri(&tetri[game->cur], game,
			tetri[game->cur].x + 1, tetri[game->cur].y))
    return (0);
  tetri[game->cur].x += 1;
  print_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  return (0);
}

int	keyTurnEvent(t_game *game, t_tetri *tetri)
{
  printf("Turn tetrimino!\n");
  return (0);
}

int	keyDropEvent(t_game *game, t_tetri *tetri)
{
  int	i;

  i = 0;
  clean_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  while (check_print_tetri(&tetri[game->cur], game,
			   tetri[game->cur].x, tetri[game->cur].y + i))
    i++;
  tetri[game->cur].y += i;
  print_tetri(&tetri[game->cur], game, tetri[game->cur].x, tetri[game->cur].y);
  return (0);
}
