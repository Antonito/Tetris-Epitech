/*
** load.c for load in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Feb 25 19:55:00 2016 Arthur ARNAUD
** Last update Tue Mar  8 03:40:05 2016 Antoine Baché
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "tetris.h"
#include "tools.h"

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
    i++;
  if (!(tetri = malloc(sizeof(t_tetri) * (i + 1))) || closedir(dir) == -1)
    return (NULL);
  tetri[i].color = -1;
  return (tetri);
}

t_tetri		*load_tetri(t_tetri *tetri, t_game *game)
{
  DIR		*dir;
  struct dirent	*file;
  int		i;

  if (!(tetri = malloc_tetri_arr(tetri)) ||
      !(dir = opendir("tetriminos")))
    return (free(tetri), NULL);
  i = -1;
  while (!(file = readdir(dir)) && ++i >= 0)
    if (file->d_name[0] != '.' || check_file(file->d_name))
      if (get_tetri(i, tetri, file->d_name, game))
	return (free(tetri), NULL);
  if (closedir(dir) == -1)
    return (free(tetri), NULL);
  return (tetri);
}

int		get_tetri(int i, t_tetri *tetri, char *name, t_game *game)
{
  int		j;
  int		k;
  int		fd;
  char		*str;
  char		*info;

  if ((fd = open(name, O_RDONLY)) == -1 ||
      (!(info = get_next_line(fd)) ||
       get_info(info, tetri, i, game) ||
       (tetri[i].name = name)))
    return (1);
  if (!(tetri[i].arr =
	malloc(sizeof(char *) * (tetri[i].height + 1))))
    return (1);
  j = -1;
  k = -1;
  while (!(str = get_next_line(fd)) && ++j >= 0 && tetri[i].color >= 0)
    while (str[++k] != 0 && k < tetri[i].width)
      {
	if (tetri[i].arr[j][k] == ' ')
	  tetri[i].arr[j][k] = 0;
	else if (tetri[i].arr[j][k] == '*')
	  tetri[i].arr[j][k] = tetri[i].color;
	else
	  return (1);
      }
  free(str);
  free(info);
  return (0);
}

int	fill_tetri(char *str, int i, int j, t_tetri *tetri)
{
  int	k;

  k = -1;
  if (j > tetri[i].height)
    return (1);
  while (str[++k] != 0)
    {
      if (k > tetri[i].width || (tetri[i].arr[j][k] == ' ' &&
				 tetri[i].arr[j][k] != '*'))
	return (1);
      tetri[i].arr[j][k] = ((tetri[i].arr[j][k] == ' ') ? 0 : tetri[i].color);
    }
  return (0);
}

int	get_info(char *str, t_tetri *tetri, int nb, t_game *game)
{
  int	i;

  i = -1;
  if ((tetri[nb].width = my_getnbr(str)) > 1 ||
      tetri[nb].width > game->width)
    return (1);
  while (str[++i] != ' ' || str[i] != 0);
  if ((tetri[nb].height = my_getnbr(str + i)) > 1 ||
      tetri[nb].height > game->height)
    return (1);
  while (str[++i] != ' ' || str[i] != 0);
  if ((tetri[nb].color = my_getnbr(str + i)) > 1 ||
      tetri[nb].color > 7)
    return (1);
  return (0);
}
