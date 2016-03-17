/*
** load.c for load in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Feb 25 19:55:00 2016 Arthur ARNAUD
** Last update Thu Mar 17 22:47:40 2016 Antoine Baché
*/

#include "tetris.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tools.h"

int		getShape(int fd, t_tetri *tetri)
{
  int		i;
  char		*str;

  if (!(tetri->arr = malloc(sizeof(char *) * (tetri->height + 1))))
    return (tetri->arr = NULL, 1);
  tetri->arr[tetri->height] = NULL;
  i = -1;
  while ((str = get_next_line(fd)))
    {
      if (++i < tetri->height && !(tetri->arr[i] = my_strdup(str)))
	return (free(str), 1);
      free(str);
    }
  if (i != tetri->height - 1)
    return (error("Error while parsing tetrimino\n"));
  return (setColor(tetri), 0);
}

int		getInfos(int fd, t_tetri *tetri, int width, int height)
{
  char		*str;
  char		**infos;

  if (!(str = get_next_line(fd)) ||
      !(infos = my_str_to_wordtab(str, 3)))
    return (error("Cannot malloc\n"));
  free(str);
  if ((tetri->width = my_getnbr(infos[0])) < 1 || tetri->width > width ||
      (tetri->height = my_getnbr(infos[1])) < 1 || tetri->height > height ||
      (tetri->color = my_getnbr(infos[2])) < 1 || tetri->color > 7)
    tetri->error = true;
  free2DArray(infos);
  return (getShape(fd, tetri));
}

int		getTetrimino(char *name, t_tetri *tetri, t_game *game)
{
  int		fd;

  if (!(tetri->name = clean_name(my_strdup(name))))
    return (1);
  if (!(name = add_dir_name(name)))
    return (error("Cannot malloc\n"));
  if ((fd = open(name, O_RDONLY)) < 0)
    return (free(name), error("Cannot open file\n"));
  free(name);
  if (getInfos(fd, tetri, game->width, game->height))
    return (close(fd), 1);
  if (close(fd) < 0)
    return (error("Cannot close file\n"));
  return (0);
}

t_tetri		*malloc_tetri_arr(t_tetri *tetri)
{
  DIR		*dir;
  int		i;
  struct dirent	*dent;

  i = 0;
  dir = NULL;
  if (!(dir = opendir("tetriminos")))
    return (NULL);
  while ((dent = readdir(dir)))
    if (my_strcmp(dent->d_name, ".\0") &&
	my_strcmp(dent->d_name, "..\0") && check_file(dent->d_name))
      i++;
  if (!(tetri = malloc(sizeof(t_tetri) * (i + 1))))
    return (closedir(dir), NULL);
  my_memset(tetri, 0, sizeof(t_tetri) * (i + 1));
  tetri[i].color = -1;
  return ((closedir(dir) == -1) ? NULL : tetri);
}

t_tetri		*load_tetri(t_tetri *tetri, t_game *game)
{
  DIR		*dir;
  int		i;
  char		**names;

  if (!(tetri = malloc_tetri_arr(tetri)) ||
      !(dir = opendir("tetriminos")))
    return (free(tetri), NULL);
  if (!(names = getNames(dir)))
    return (closedir(dir), free(tetri), NULL);
  i = -1;
  while (names[++i])
    if (getTetrimino(names[i], &tetri[i], game))
      return (closedir(dir), free(tetri), free2DArray(names), NULL);
  if (closedir(dir) == -1)
    return (free(tetri), free2DArray(names), NULL);
  return (free2DArray(names), tetri);
}
