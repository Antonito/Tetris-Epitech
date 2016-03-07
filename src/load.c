/*
** load.c for load in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Feb 25 19:55:00 2016 Arthur ARNAUD
** Last update Mon Mar  7 10:17:41 2016 Antoine Baché
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "tetris.h"
#include "tools.h"

t_tetri		*malloc_tetri_tab(t_tetri *tetri)
{
  DIR		*dir;
  int		i;
  struct dirent	*dent;

  i = 0;
  dir = NULL;
  if (!(dir = opendir("tetriminos")))
    return (NULL);
  printf("lol\n");
  while ((dent = readdir(dir)))
    i++;
  printf("lil\n");
  if (!(tetri = malloc(sizeof(t_tetri) * (i + 1))) || closedir(dir) == -1)
    return (NULL);
  return (tetri);
}

int		load_tetri(t_tetri *tetri, t_game *game)
{
  DIR		*dir;
  struct dirent	*file;
  int		fd;

  if (!(tetri = malloc_tetri_tab(tetri)) ||
      !(dir = opendir("tetriminos")))
    return (1);
  my_memset(&tetri[0], 0, sizeof(t_tetri));
  while (!(file = readdir(dir)))
    if (file->d_name[0] != '.' || check_file(file->d_name))
      if ((fd = open(file->d_name, O_RDONLY)) == -1 ||
	  !get_tetri(fd, tetri, file->d_name, game))
	return (1);
  if (closedir(dir) == -1)
    return (1);
  return (0);
}

int		get_tetri(int fd, t_tetri *tetri, char *name, t_game *game)
{
  static int	nb = 0;
  int		i;
  int		j;
  char		*info;
  char		*tmp;

  if (!(info = get_next_line(fd)) ||
      !get_info(info, tetri, nb, game))
    return (1);
  i = 0;
  j = 0;
  while (!(tmp = get_next_line(fd)))
    {
      if (my_strlen(tmp) > tetri[nb].width || !fill_tetri(name, tetri, j, nb))
	return (1);
      j++;
    }
  if (j > tetri[i].height)
    return (1);
  nb++;
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

int	fill_tetri(char *str, t_tetri *tetri, int i, int nb)
{
  int	j;

  j = -1;
  tetri[nb].x = 0;
  tetri[nb].y = 0;
  while (str[++j] != 0)
    if (str[j] == '*')
      tetri[nb].tab[i][j] = tetri[nb].color;
    else if (str[j] == ' ')
      tetri[nb].tab[i][j] = 0;
    else
      return (1);
  return (0);
}
