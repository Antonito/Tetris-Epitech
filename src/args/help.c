/*
** help.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/src/args
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 19:56:14 2016 Antoine Baché
** Last update Tue Mar  8 11:04:04 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

void	displayHelp(void)
{
  write(1, "  --help                 ", 25);
  write(1, "Display this help\n", 18);
  write(1, "  -l --level={num}       ", 25);
  write(1, "Start Tetris at level num\n", 26);
  write(1, "  -kl --key-left={k}     ", 25);
  write(1, "Move tetrimino on LEFT with key K\n", 34);
  write(1, "  -kr --key-right={k}    ", 25);
  write(1, "Move tetrimino on RIGHT with key K\n", 35);
  write(1, "  -kt --key-turn={k}     ", 25);
  write(1, "Turn tetrimino with key K\n", 26);
  write(1, "  -kd --key-drop={k}     ", 25);
  write(1, "Set default DROP on key K\n", 26);
  write(1, "  -kq --key-pause={k}    ", 25);
  write(1, "Quit program when press key K\n", 30);
  write(1, "  --map-size={row,col}   ", 25);
  write(1, "Set game size at row, col\n", 26);
  write(1, "  -w --without-next      ", 25);
  write(1, "Hide next tetrimino\n", 20);
  write(1, "  -d --debug             ", 25);
  write(1, "Debug mode\n", 11);
}

int	helpArg(t_game *game, char **av, bool mode)
{
  --av;
  write(1, "Usage: ", 7);
  write(1, av[0], my_strlen(av[0]));
  write(1, " [options]\n", 11);
  write(1, "Options\n", 8);
  displayHelp();
  return ((void)game, (void)mode, 1);
}
