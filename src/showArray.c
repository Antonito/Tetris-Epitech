/*
** showArray.c for showArray in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar  8 04:42:15 2016 Arthur ARNAUD
** Last update Tue Mar  8 05:24:27 2016 Arthur ARNAUD
*/

#include "tetris.h"

int	showArray(t_tetri *tetri)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  while (tetri[++i].color >= 0)
    {
      if (write(1, "Tetriminos : Name ", 18) == -1 ||
	  write(1, tetri[i].name, my_strlen(tetri[i].name)) == -1 ||
	  write(1, " : Size ", 8) == -1 ||
	  my_putnbr(tetri[i].widht) ||
	  write(1, "*", 1) == -1 ||
	  my_putnbr(tetri[i].height) ||
	  write(1, " : Color ", 9) == -1 ||
	  my_putnbr(tetri[i].color) ||
	  write(1, " :\n", 3) == -1)
	return (1);
      j = -1;
      while (++j < tetri[i].height)
	{
	  k = -1;
	  while (++k < tetri[i].width)
	    if (write(1, (tetri[i].arr[j][k] > 0) ? "0" : "*"), 1)
	      return (1);
    }
}
