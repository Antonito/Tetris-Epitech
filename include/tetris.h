/*
** tetris.h for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 14:11:45 2016 Antoine Baché
** Last update Thu Feb 25 17:30:52 2016 Arthur ARNAUD
*/

#ifndef	TETRIS_H_
# define TETRIS_H_

# include <ncurses.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_window
{
  WINDOW	*title;
  WINDOW	*score;
  WINDOW	*board;
  WINDOW	*next;
}		t_window;

typedef struct	s_tetri
{
  char		**tab;
  int		height;
  int		width;
  int		x;
  int		y;
}		t_tetri;

typedef struct	s_game
{
  char		level;
  char		next;
  int		lines;
  int		score;
  int		highscore;
  int		time_sec;
  int		time_min;
  int		height;
  int		width;
  char		**tab;
}		t_game;

/*
** ===================================================
**                       INIT
** ===================================================
*/
int	tetris(void);
int	init_game(t_game *, t_tetri *);
char	**malloc_tab(char **, int, int);
void	my_memset(void *, char, int);
void	init_pair_color();
WINDOW	*create_new_win(int, int, int, int);
WINDOW	*create_new_board(int, int, int, int);
int	create_all_win(t_window *, t_tetri *, t_game *);

/*
** ===================================================
**                      DISPLAY
** ===================================================
*/
int	display(t_window *, t_tetri *, t_game *);
void	display_score(WINDOW *, t_game *);
void	display_title(WINDOW *);
void	display_interface(t_window *, t_game *);
void	display_board(t_window *, t_tetri *, t_game *);
void	display_tetriminos(WINDOW *, char **, int);

#endif /* TETRIS_H_ */
