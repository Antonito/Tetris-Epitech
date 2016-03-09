/*
** order.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar  9 00:04:13 2016 Antoine Baché
** Last update Wed Mar  9 01:35:23 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

void		setColor(t_tetri *tetri)
{
  int		i;
  int		j;

  i = -1;
  while (tetri->arr[++i] && (j = -1))
    while (tetri->arr[i][++j])
      if (tetri->arr[i][j] == '*')
	tetri->arr[i][j] = (char)tetri->color;
}

int		countFiles(void)
{
  DIR		*count;
  struct dirent	*file;
  int		i;

  i = 0;
  if (!(count = opendir("tetriminos")))
    return (0);
  while ((file = readdir(count)))
    if (file->d_name[0] != '.' && check_file(file->d_name))
      ++i;
  if (closedir(count) < 0)
    return (0);
  return (i);
}

char		**orderNames(char **name, int nb)
{
  char		**ordered;

  ordered = name;
  return (ordered);
}

char		**getNames(DIR *dir)
{
  int		i;
  struct dirent	*file;
  char		**names;
  int		nb;

  if (!(nb = countFiles()))
    return (error("Not enough tetrimino\n"), NULL);
  if (!(names = malloc(sizeof(char *) * (nb + 1))))
    return (error("Cannot malloc\n"), NULL);
  i = 0;
  while ((file = readdir(dir)))
    if (file->d_name[0] != '.' && check_file(file->d_name) &&
	!(names[i++] = my_strdup(file->d_name)))
      return (error("Cannot malloc\n"), NULL);
  names[nb] = NULL;
  return ((names = orderNames(names, nb)));
}
