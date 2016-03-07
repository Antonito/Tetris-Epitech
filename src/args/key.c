/*
** key.c for Tetris in /PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Mar  7 09:57:00 2016 Antoine Baché
** Last update Mon Mar  7 10:42:44 2016 Antoine Baché
*/

#include "tetris.h"

int	getKey(int *key, const char *key_str)
{
  if (key_str[0] == '^')
    printf("Special key!\n");
  printf("Key is %s\n", key_str);
  return (0);
}