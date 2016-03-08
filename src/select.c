/*
** select.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 17:01:11 2016 Antoine Baché
** Last update Tue Mar  8 02:48:41 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

event		selectorEvent(void)
{
  event		array;

  if ((array = malloc(sizeof(int *) * (6))) == NULL)
    return (NULL);
  array[LEFT] = &keyLeftEvent;
  array[RIGHT] = &keyRightEvent;
  array[DROP] = &keyDropEvent;
  array[TURN] = &keyTurnEvent;
  array[PAUSE] = &keyPauseEvent;
  array[QUIT] = &keyQuitEvent;
  return (array);
}

int		errorArg(t_game *game, char **av, bool mode)
{
  (void)game;
  (void)mode;
  --av;
  write(1, "Usage: ", 7);
  write(1, av[0], my_strlen(av[0]));
  write(1, " [options]\n", 11);
  return (1);
}

void		setActions(ptrtab array)
{
  array[0] = &helpArg;
  array[1] = &levelArg;
  array[2] = &levelArg;
  array[3] = &keyLeftArg;
  array[4] = &keyLeftArg;
  array[5] = &keyRightArg;
  array[6] = &keyRightArg;
  array[7] = &keyTurnArg;
  array[8] = &keyTurnArg;
  array[9] = &keyDropArg;
  array[10] = &keyDropArg;
  array[11] = &keyQuitArg;
  array[12] = &keyQuitArg;
  array[13] = &keyPauseArg;
  array[14] = &keyPauseArg;
  array[15] = &sizeArg;
  array[16] = &nextArg;
  array[17] = &nextArg;
  array[18] = &debugArg;
  array[19] = &debugArg;
  array[20] = &errorArg;
}

ptrtab		selector(void)
{
  ptrtab	array;

  if ((array = malloc(sizeof(int *) * (NB_ARGS + 1))) == NULL)
    return (NULL);
  setActions(array);
  return (array);
}
