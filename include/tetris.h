/*
** tetris.h for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 14:11:45 2016 Antoine Baché
** Last update Wed Feb 24 14:22:45 2016 Arthur ARNAUD
*/

#ifndef	TETRIS_H_
# define TETRIS_H_

# include <ncurses.h>

typedef struct	s_window
{
  WINDOW	*title;
  WINDOW	*score;
  WINDOW	*board;
  WINDOW	*next;
}		t_window;

typedef struct	s_tetri
{
  char		**tetri;
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

WINDOW	*create_new_win(int height, int width, int start_y, int start_x);
WINDOW	*create_new_board(int height, int width, int start_y, int start_x);
void	init_pair_color();
void	display();
void	display_score(WINDOW *win);
void	display_title(WINDOW *win);
void	display_title_(WINDOW *win);
void	display_interface();
void	display_board();
void	display_tetriminos(WINDOW *win, char **tab, int height, int width);

#endif /* TETRIS_H_ */
