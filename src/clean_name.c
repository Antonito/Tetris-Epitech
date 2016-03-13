/*
** clean_name.c for Tetris in /Prog_Elem/PSU_2015_tetris
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 13 04:06:23 2016 Antoine Baché
** Last update Sun Mar 13 04:09:55 2016 Antoine Baché
*/

#include <stdlib.h>
#include <unistd.h>
#include "tools.h"

char	*clean_name(char *str)
{
  int	i;
  char	*res;

  i = -1;
  if (!(res = malloc(sizeof(char) * (my_strlen(str) + 1))))
    return (write(2, "Malloc failed\n", 14), NULL);
  while (str && str[++i] && str[i] != '.' && (res[i] = str[i]));
  res[i] = '\0';
  return (free(str), res);
}
