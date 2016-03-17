/*
** order.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar  9 00:04:13 2016 Antoine Baché
** Last update Thu Mar 17 22:53:00 2016 Antoine Baché
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
      else
	tetri->arr[i][j] = -1;
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
    if (my_strcmp(file->d_name, ".\0") &&
	my_strcmp(file->d_name, "..\0") && check_file(file->d_name))
      ++i;
  if (closedir(count) < 0)
    return (0);
  return (i);
}

int		isOrdered(const char **name)
{
  int		i;
  int		j;

  i = -1;
  while (name[++i] && (j = i) > -1)
    {
      while (name[++j])
	{
	  if (my_strcmp(name[i], name[j]) > 0)
	    return (1);
	}
    }
  return (0);
}

char		**orderNames(char **name)
{
  char		*tmp;
  int		i;
  int		j;

  i = -1;
  while (isOrdered((const char **)name) && name[++i] && (j = i) > -1)
    {
      while (name[++j])
	{
	  if (my_strcmp(name[i], name[j]) > 0)
	    {
	      if (!(tmp = my_strdup(name[i])))
		return (error("Cannot malloc\n"), NULL);
	      if (free(name[i]), !(name[i] = my_strdup(name[j])))
		return (error("Cannot malloc\n"), NULL);
	      if (free(name[j]), !(name[j] = my_strdup(tmp)))
		return (error("Cannot malloc\n"), NULL);
	      free(tmp);
	    }
	}
    }
  return (name);
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
    if (my_strcmp(file->d_name, ".\0") &&
	my_strcmp(file->d_name, "..\0") && check_file(file->d_name) &&
	!(names[i++] = my_strdup(file->d_name)))
      return (error("Cannot malloc\n"), NULL);
  names[nb] = NULL;
  return ((names = orderNames(names)));
}
