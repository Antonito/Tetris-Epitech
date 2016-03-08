/*
** my_str_to_wordtab.c for Tetris in /PSU_2015_tetris
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 21:55:34 2016 Antoine Baché
** Last update Tue Mar  8 21:57:23 2016 Antoine Baché
*/

#include "tools.h"

char	**my_str_to_wordtab(const char *str, const int line)
{
  char	**tab;
  int	count;
  int	i;
  int	j;

  if ((tab = malloc(sizeof(char *) * (line + 1))) == NULL)
    return (NULL);
  count = -1;
  while (++count < line)
    {
      i = -1;
      j = -1;
      while (str[++i] != ' ' && str[i] != '\0');
      if ((tab[count] = malloc(i + 1)) == NULL)
	return (NULL);
      while (++j < i && (tab[count][j] = str[j]));
      tab[count][j] = 0;
      str += (i + 1);
    }
  tab[count] = NULL;
  return (tab);
}
