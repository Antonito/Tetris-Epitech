/*
** add_dir_name.c for add_dir_name in /PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar  8 16:59:40 2016 Arthur ARNAUD
** Last update Wed Mar  9 01:22:56 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

char	*add_dir_name(char *name)
{
  int	i;
  int	j;
  char	*res;
  char	*dir;

  i = -1;
  j = -1;
  if (!(dir = my_strdup("tetriminos/")) ||
      !(res = malloc(sizeof(char) * (my_strlen(name) + my_strlen(dir) + 1))))
    return (NULL);
  while (dir[++i] != 0)
    res[i] = dir[i];
  while (name[++j] != 0)
    res[i++] = name[j];
  res[i] = 0;
  free(dir);
  return (res);
}
