/*
** getTerm.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 00:25:42 2016 Antoine Baché
** Last update Tue Mar  8 07:20:26 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

int			initTerm(const char *term, bool mode)
{
  static struct termios old;
  struct termios	new;

  if (!term && !mode)
    return (write(2, "Unknown term\n", 13), 1);
  if (!mode)
    {
      if (ioctl(0, TCGETS, &old) == -1)
	return (1);
      new = old;
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      new.c_cc[VMIN] = 0;
      new.c_cc[VTIME] = 1;
      if (ioctl(0, TCSETS, &new) == -1)
	return (1);;
      return (0);
    }
  else if (mode && ioctl(0, TCSETS, &old) == -1)
    return (1);
  return (0);
}

char			*getTerm(const char **env)
{
  int			i;

  i = 0;
  while (env[i])
    {
      if (!my_strncmp("TERM=", env[i], 5))
	return ((char *)(env[i] + 5));
      ++i;
    }
  return (NULL);
}
