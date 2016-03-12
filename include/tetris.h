/*
** tetris.h for Tetris in /PSU_2015_tetris/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 14:11:45 2016 Antoine Baché
** Last update Sat Mar 12 01:45:07 2016 Arthur ARNAUD
*/

#ifndef	TETRIS_H_
# define TETRIS_H_
# define NB_ARGS		20
# define NB_KEYS		6
# define MIN_ROW		20
# define MAX_ROW		80
# define MIN_COL		10
# define MAX_COL		80
# define BUFF_SIZE		4096
# define BETWEEN(A, MIN, MAX)	(((A) >= (MIN)) ? (((A) <= (MAX)) ? 1 : 0) : 0)

# define _BDS_SOURCE
# define _POSIX_SOURCE
# define _DEFAULT_SOURCE

# include <time.h>
# include <ncurses.h>
# include <curses.h>
# include <term.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <dirent.h>

typedef	enum	e_mode
  {
    SHORT,
    LONG
  }		t_mode;

typedef	enum	e_keys
  {
    LEFT,
    RIGHT,
    DROP,
    TURN,
    PAUSE,
    QUIT,
    UNKNOWN
  }		t_keys;

typedef struct	s_window
{
  WINDOW	*title;
  WINDOW	*score;
  WINDOW	*board;
  WINDOW	*next;
}		t_window;

typedef struct	s_tetri
{
  char		**arr;
  char		*name;
  bool		error;
  int		height;
  int		width;
  int		color;
  int		x;
  int		y;
}		t_tetri;

typedef struct	s_time
{
  time_t	count;
  time_t	tick;
  time_t	check;
}		t_time;

typedef struct	s_game
{
  char		level;
  char		next;
  int		line;
  int		score;
  int		highscore;
  int		time_sec;
  int		time_min;
  int		height;
  int		width;
  bool		showNext;
  bool		debug;
  bool		running;
  int		cur;
  char		**tetri;
  char		**arr;
  char		**keys;
}		t_game;

typedef struct	s_loop
{
  t_tetri	*tetri;
  t_window	win;
  int		(**events)(t_game *, t_tetri *);
  char		buff[BUFF_SIZE];
  int		i;
  int		next;
  int		cur;
  int		check;
}		t_loop;

typedef		int (**ptrtab)(t_game *, char **, bool);
typedef		int (**event)(t_game *, t_tetri *);

/*
** ===================================================
**                      TO ORDER
** ===================================================
*/
void		checkPause(bool *, char **, WINDOW *, time_t *);
bool		isOver(t_game *);
int		debugMode(t_game *, t_tetri *, char *);
void		getTermSize(int *, int *);
void		freeWin(t_window *);
void		freeTetri(t_tetri *);
void		freeKeys(char **);
void		free2DArray(char **);
int		error(const char *);
int		check_file(char *);

/*
** ===================================================
**                       EVENTS
** ===================================================
*/
event		selectorEvent(void);
int		keyLeftEvent(t_game *, t_tetri *);
int		keyRightEvent(t_game *, t_tetri *);
int		keyTurnEvent(t_game *, t_tetri *);
int		keyDropEvent(t_game *, t_tetri *);
int		keyQuitEvent(t_game *, t_tetri *);
int		keyPauseEvent(t_game *, t_tetri *);

/*
** ===================================================
**                     CHECK ARGS
** ===================================================
*/
int		initTerm(const char *, bool);
char		*getTerm(const char **);
ptrtab		selector(void);
int		check_args(int, char **, char **);

/*
** ===================================================
**                       ARGS
** ===================================================
*/
int		getKey(int *, const char *);
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
void		setColor(t_tetri *);
char		**getNames(DIR *);
t_tetri		*load_tetri(t_tetri *, t_game *);
char		*add_dir_name(char *);
int		fill_tetri(char *, int, int, t_tetri *);
int		get_tetri(int, t_tetri *, char *, t_game *);
int		get_info(char *, t_tetri *, int, t_game *);
t_tetri		*my_realloc_tab(t_tetri *);

/*
** ===================================================
**                       INIT
** ===================================================
*/
int		tetris(t_game *, char *);
int		init_game(t_game *, t_tetri *);
int		init_display(t_window *, t_game *, char *);
char		**malloc_tab(char **, int, int);
void		my_memset(void *, char, int);
void		init_pair_color();
WINDOW		*create_new_win(int, int, int, int);
WINDOW		*create_new_board(int, int, int, int);
int		create_all_win(t_window *, t_game *);

/*
** ===================================================
**                      GAME
** ===================================================
*/
int		add_tetri(t_tetri *, t_game *);
int		check_line(t_game *, t_tetri *);
int		line_full(t_game *, int);
void		fall_all_tetri(t_game *, int);
int		fall_tetri(t_game *, t_tetri *);
int		check_print_tetri(t_tetri *, t_game *, int, int);
int		check_end(t_game *);
void		clean_tetri(t_tetri *, t_game *, int, int);
void		print_tetri(t_tetri *, t_game *, int, int);
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
