/*
** help.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 19:56:14 2016 Antoine Baché
** Last update Sun Mar  6 20:02:02 2016 Antoine Baché
*/

#include "tetris.h"

int	helpArg(t_game *game, char **av, bool mode)
{
  if (write(1, "Usage: ./tetris [options]\n", 26) < 0 ||
      write(1, "Options\n", 8) < 0 ||
      write(1, "--help\n", 7) < 0 ||
      write(1, "-l --level={num}\n", 17) < 0 ||
      write(1, "-kl --key-left={k}\n", 19) < 0 ||
      write(1, "-kr --key-right={k}\n", 20) < 0 ||
      write(1, "-kt --key-turn={k}\n", 19) < 0 ||
      write(1, "-kd --key-drop={k}\n", 19) < 0 ||
      write(1, "-kq --key-pause={k}\n", 20) < 0 ||
      write(1, "--map-size={row,col}\n", 21) < 0 ||
      write(1, "-w --without-next\n", 18) < 0 ||
      write(1, "-d --debug\n", 11) < 0)
    return (1);
  return (0);
}
