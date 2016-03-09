/*
** pause.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar  9 10:16:13 2016 Antoine Baché
** Last update Wed Mar  9 10:36:43 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

void	checkPause(bool *running, char **keys, WINDOW *score)
{
  char	buff[BUFF_SIZE];

  if (!*(running))
    {
      mvwprintw(score, 7, 2, "Game is paused !");
      wrefresh(score);
    }
  while (!(*running))
    {
      my_memset(buff, 0, BUFF_SIZE);
      read(0, buff, BUFF_SIZE - 1);
      if (!my_strncmp(buff, keys[PAUSE], my_strlen(buff) + 1))
	{
	  *running = true;
	  wclear(score);
	}
    }
}
