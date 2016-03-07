/*
** errors.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Mar  7 21:13:43 2016 Antoine Baché
** Last update Mon Mar  7 21:18:34 2016 Antoine Baché
*/

#include "tools.h"

int	error(const char *str)
{
  write(2, str, my_strlen(str));
  return (1);
}
