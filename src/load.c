/*
** load.c for load in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Feb 25 19:55:00 2016 Arthur ARNAUD
** Last update Thu Feb 25 20:25:40 2016 Arthur ARNAUD
*/

#include "tetris.h"

int		load_tetri(t_tetri *tetri)
{
  DIR		*dir;
  struct dirent	*file;
  int		fd;

  if (!(dir = opendir("tetriminos")))
    return (1);
  while (!(file = readdir(dir)))
    if ((fd = open(file->d_name)) == -1 || !get_tetri(fd, tetri))
      return (1);
  if (closedir(dir) == -1)
    return (1);
  return (0);
}
