/*
** debug.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 07:41:30 2016 Antoine Baché
** Last update Wed Mar  9 14:19:44 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

int	writeKey(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    if (str[i] != ' ' && str[i] != 27 && write(1, &str[i++], 1) < 0)
      return (1);
    else if (str[i] == ' ' && ++i && write(1, "(space)", 7) < 0)
      return (1);
    else if (str[i] == 27 && ++i && write(1, "^E", 2) < 0)
      return (1);
  if (write(1, "\n", 1) < 0)
    return (1);
  return (0);
}

void	showKeys(t_game *game)
{
  if (write(1, "Key Left : ", 11) < 0 ||
      writeKey(game->keys[LEFT]) < 0 ||
      write(1, "Key Right : ", 12) < 0 ||
      writeKey(game->keys[RIGHT]) < 0 ||
      write(1, "Key Turn : ", 11) < 0 ||
      writeKey(game->keys[TURN]) < 0 ||
      write(1, "Key Drop : ", 11) < 0 ||
      writeKey(game->keys[DROP]) < 0 ||
      write(1, "Key Quit : ", 11) < 0 ||
      writeKey(game->keys[QUIT]) < 0 ||
      write(1, "Key Pause : ", 12) < 0 ||
      writeKey(game->keys[PAUSE]) < 0)
    return ;
}

void	showMoreTetriminos(t_tetri *tetri, int nb)
{
  int	i;
  int	j;

  if (tetri[nb].error && write(1, "Error\n", 6 >= -1))
    return ;
  if (write(1, "Size ", 5) < 0 || my_put_nbr(tetri[nb].height) < 0 ||
      write(1, "*", 1) < 0 || my_put_nbr(tetri[nb].width) < 0 ||
      write(1, " : Color ", 9) < 0 || my_put_nbr(tetri[nb].color) < 0 ||
      write(1, " :\n", 3) < 0)
    return ;
  i = -1;
  while (++i < tetri[nb].height && (j = -1))
    {
      while (tetri[nb].arr[i][++j])
	if (((tetri[nb].arr[i][j] != ' ') ? write(1, "*", 1) :
	     write(1, &tetri[nb].arr[i][j], 1)) < 0)
	  return ;
      if (write(1, "\n", 1) < 0)
	return ;
    }
}

void	showTetriminos(t_tetri *tetri)
{
  int	nb;

  nb = 0;
  while (tetri[nb].color != -1 && ++nb);
  if (write(1, "Tetriminos : ", 13) < 0 || my_put_nbr(nb) < 0 ||
      write(1, "\n", 1) < 0)
    return ;
  nb = 0;
  while (tetri[nb].color != -1)
    {
      if (write(1, "Tetriminos : Name ", 18) < 0 ||
	  write(1, tetri[nb].name, my_strlen(tetri[nb].name)) < 0 ||
	  write(1, " : ", 3) < 0)
	return ;
      showMoreTetriminos(tetri, nb);
      ++nb;
    }
}

int	debugMode(t_game *game, t_tetri *tetri, char *term)
{
  char	buff[BUFF_SIZE];

  if (write(1, "*** DEBUG MODE ***\n", 19) < 0)
    return (1);
  showKeys(game);
  if (write(1, "Next : ", 7) < 0 ||
      ((game->showNext) ? write(1, "Yes\n", 4) : write(1, "No\n", 3)) < 0 ||
      write(1, "Level : ", 8) < 0 ||
      my_put_nbr((int)game->level) < 0 || write(1, "\n", 1) < 0 ||
      write(1, "Size : ", 7) < 0 || my_put_nbr(game->height) < 0 ||
      write(1, "*", 1) < 0 || my_put_nbr(game->width) < 0 ||
      write(1, "\n", 1) < 0)
    return (1);
  showTetriminos(tetri);
  if (write(1, "Press a key to start Tetris\n", 28) < 0)
    return (1);
  if (initTerm(term, false))
    return (error("Cannot init term\n"));
  my_memset(buff, 0, BUFF_SIZE);
  while (!buff[0])
    read(0, buff, BUFF_SIZE - 1);
  if (initTerm(term, false))
    return (error("Cannot init term\n"));
  return (0);
}
