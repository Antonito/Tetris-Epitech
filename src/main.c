/*
** main.c for main in /home/arnaud_e/rendu/psu/PSU_2015_tetris
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 19:12:02 2016 Arthur ARNAUD
** Last update Sun Mar  6 20:12:53 2016 Antoine Baché
*/

#include "tetris.h"

int		tetris(t_game *game)
{
  printf("THIS IS THE GAME !\n");
  return (0);
}

int		main(int ac, char **av, char **env)
{
  if (!env || check_args(ac, av))
    return (1);
  return (0);
}
