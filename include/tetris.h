/*
** tetris.h for Tetris in /home/bache_a/work/Prog_Elem/PSU_2015_tetris/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 14:11:45 2016 Antoine Baché
** Last update Mon Mar  7 08:35:31 2016 Antoine Baché
*/

#ifndef	TETRIS_H_
# define TETRIS_H_
# define NB_ARGS		20
# define MIN_ROW		20
# define MAX_ROW		80
# define MIN_COL		10
# define MAX_COL		80
# define BETWEEN(A, MIN, MAX)	(((A) >= (MIN)) ? (((A) <= (MAX)) ? 1 : 0) : 0)

# include <ncurses.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef	enum	e_mode
  {
    SHORT,
    LONG
  }		t_mode;

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
  char		*name;
  int		height;
  int		width;
  int		color;
  int		x;
  int		y;
}		t_tetri;

typedef	struct	s_key
{
  int		left;
  int		right;
  int		turn;
  int		drop;
  int		quit;
  int		pause;
}		t_key;

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
  bool		showNext;
  bool		debug;
  char		**tab;
}		t_game;

typedef		int (**ptrtab)(t_game *, char **, bool);

/*
** ===================================================
**                      TO ORDER
** ===================================================
*/
int		check_file(char *);

/*
** ===================================================
**                     CHECK ARGS
** ===================================================
*/
ptrtab		selector(void);
int		check_args(int, char **);

/*
** ===================================================
**                       ARGS
** ===================================================
*/
int		helpArg(t_game *, char **, bool);
int		levelArg(t_game *, char **, bool);
int		keyLeftArg(t_game *, char **, bool);
int		keyRightArg(t_game *, char **, bool);
int		keyTurnArg(t_game *, char **, bool);
int		keyDropArg(t_game *, char **, bool);
int		keyQuitArg(t_game *, char **, bool);
int		keyPauseArg(t_game *, char **, bool);
int		sizeArg(t_game *, char **, bool);
int		nextArg(t_game *, char **, bool);
int		debugArg(t_game *, char **, bool);
int		errorArg(t_game *, char **, bool);

/*
** ===================================================
**                       LOAD
** ===================================================
*/
int		load_tetri(t_tetri *, t_game *);
int		get_tetri(int, t_tetri *, char *, t_game *);
int		get_info(char *, t_tetri *, int, t_game *);
int		fill_tetri(char *, t_tetri *, int, int);
t_tetri		*my_realloc_tab(t_tetri *);

/*
** ===================================================
**                       INIT
** ===================================================
*/
int		tetris(t_game *);
int		init_game(t_game *, t_tetri *);
char		**malloc_tab(char **, int, int);
void		my_memset(void *, char, int);
void		init_pair_color();
WINDOW		*create_new_win(int, int, int, int);
WINDOW		*create_new_board(int, int, int, int);
int		create_all_win(t_window *, t_tetri *, t_game *);

/*
** ===================================================
**                      DISPLAY
** ===================================================
*/
int		display(t_window *, t_tetri *, t_game *);
void		display_score(WINDOW *, t_game *);
void		display_title(WINDOW *);
void		display_interface(t_window *, t_game *);
void		display_board(t_window *, t_tetri *, t_game *);
void		display_tetriminos(WINDOW *, char **, int);

#endif /* TETRIS_H_ */
