/*
** size.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 20:02:32 2016 Antoine Baché
** Last update Fri Mar 11 03:41:58 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

int	parseSize(const char *str, t_game *game)
{
  int	i;
  int	j;
  int	row;
  int	col;
  char	*tmp;

  str += 11;
  i = 0;
  j = 0;
  while (str[i] && str[i] != ',' && ++i);
  if (!(tmp = malloc(sizeof(char) * (i + 1))))
    return (1);
  while (j < i && (tmp[j] = str[j]) && ++j);
  tmp[i] = '\0';
  str += ++i;
  if (!BETWEEN((row = my_getnbr(tmp)), MIN_ROW, MAX_ROW) ||
      !BETWEEN((col = my_getnbr(str)), MIN_COL, MAX_COL))
    return (free(tmp), write(2, "Incorrect size\n", 15), 1);
  game->height = row;
  game->width = col;
  return (free(tmp), 0);
}

int	sizeArg(t_game *game, char **av, bool mode)
{
  (void)mode;
  if (my_strlen(av[0]) <= 11 || parseSize(av[0], game))
    return (1);
  return (0);
}
