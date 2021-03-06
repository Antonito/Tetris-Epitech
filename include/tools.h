/*
** tools.h for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar  6 16:15:27 2016 Antoine Baché
** Last update Thu Mar 10 02:53:02 2016 Antoine Baché
*/

#ifndef	TOOLS_H_
# define TOOLS_H_

# include <unistd.h>
# include "get_next_line.h"

int	my_getnbr(const char *);
int	my_put_nbr(int);
char	*my_strdup(char *);
char	*my_strndup(char *, int);
char	**my_str_to_wordtab(const char *, const int);
int	my_strlen(const char *);
int	my_strcmp(const char *, const char *);
int	my_strncmp(const char *, const char *, int);

#endif	/* !TOOLS_H_ */
