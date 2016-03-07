/*
** help.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 19:56:14 2016 Antoine Baché
** Last update Mon Mar  7 07:37:16 2016 Antoine Baché
*/

#include "tetris.h"

int	helpArg(t_game *game, char **av, bool mode)
{
  write(1, "Usage: ./tetris [options]\n", 26);
  write(1, "Options\n", 8);
  write(1, "  --help\t\t", 10);
  write(1, "Display this help\n", 18);
  write(1, "  -l --level={num}\t", 19);
  write(1, "Start Tetris at level num\n", 26);
  write(1, "  -kl --key-left={k}\t", 21);
  write(1, "Move tetrimino on LEFT with key K\n", 34);
  write(1, "  -kr --key-right={k}\t", 24);
  write(1, "Move tetrimino on RIGHT with key K\n", 35);
  write(1, "  -kt --key-turn={k}\t", 21);
  write(1, "Turn tetrimino with key K\n", 26);
  write(1, "  -kd --key-drop={k}\t", 21);
  write(1, "Set default DROP on key K\n", 26);
  write(1, "  -kq --key-pause={k}\t", 22);
  write(1, "Quit program when press key K\n", 30);
  write(1, "  --map-size={row,col}\t", 23);
  write(1, "Set game size at row, col\n", 26);
  write(1, "  -w --without-next\t", 20);
  write(1, "Hide next tetrimino\n", 20);
  write(1, "  -d --debug\t\t", 14);
  write(1, "Debug mode\n", 11);
  return ((void)game, (void)av, (void)mode, 1);
}
