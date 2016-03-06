/*
** my_getnbr.c for Tetris in /PSU_2015_tetris/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 16:14:18 2016 Antoine Baché
** Last update Sun Mar  6 16:14:38 2016 Antoine Baché
*/

int	my_getnbr(char *str)
{
  int	i;
  int	s;
  long	r;

  i = 0;
  s = 1;
  r = 0;
  if (!str)
    return (0);
  while (str[i] == 43 || str[i] == 45)
    {
      if (str[i] == 45)
	s = -s;
      ++i;
    }
  str += i;
  i = 0;
  while (str[i] > 47 && str[i] < 58)
    {
      r = r * 10;
      r = r + str[i] - 48;
      ++i;
    }
  return ((int)(s * r));
}
