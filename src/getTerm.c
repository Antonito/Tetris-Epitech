/*
** getTerm.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  8 00:25:42 2016 Antoine Baché
** Last update Wed Mar  9 02:19:10 2016 Antoine Baché
*/

#include "tetris.h"
#include "tools.h"

void			getTermSize(int *cols, int *line)
{
  *cols = tigetnum("cols");
  *line = tigetnum("lines");
}

int			initTerm(const char *term, bool mode)
{
  static struct termios old;
  struct termios	new;

  if (!term && !mode)
    return (write(2, "Unknown term\n", 13), 1);
  if (!mode)
    {
      if (ioctl(0, TCGETS, &old) == -1 || ioctl(0, TCGETS, &new) == -1)
	return (1);
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      new.c_cc[VMIN] = 0;
      new.c_cc[VTIME] = 1;
      if (ioctl(0, TCSETS, &new) == -1)
	return (1);
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
