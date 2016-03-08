/*
** my_put_nbr.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:06:42 2016 Antoine Baché
** Last update Tue Mar  8 08:02:14 2016 Antoine Baché
*/

#include "tools.h"

void	my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putchar(const char c)
{
  write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if (nb < 0)
    {
      if (nb == -2147483648)
	{
	  my_putstr("-2147483648");
	  return (11);
	}
      my_putchar('-');
      i++;
      nb = -nb;
    }
  if (nb >= 10)
    i += my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
  return (i);
}
