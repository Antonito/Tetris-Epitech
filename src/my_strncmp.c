/*
** my_strncmp.c for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 16:22:02 2016 Antoine Baché
** Last update Sun Mar  6 16:22:07 2016 Antoine Baché
*/

int	my_strncmp(const char *s1, const char *s2, int n)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j == 0 && s1[i] && s2[i] && i < n)
    {
      if (s1[i] != s2[i])
	j = s1[i] - s2[i];
      i = i + 1;
    }
  return ((i > 0) ? j : -1);
}
