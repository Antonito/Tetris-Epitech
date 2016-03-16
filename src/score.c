/*
** score.c for score in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 14:53:09 2016 Arthur ARNAUD
** Last update Wed Mar 16 03:04:31 2016 Arthur ARNAUD
*/

#include "tetris.h"

void	display_score(WINDOW *score, t_game *game)
{
  game->highscore = 3600;
  mvwprintw(score, 2, 2, "High Score");
  mvwprintw(score, 2, 19, "%d", game->highscore);
  mvwprintw(score, 3, 2, "Score");
  mvwprintw(score, 3, 19, "%d", game->score);
  mvwprintw(score, 5, 2, "Lines");
  mvwprintw(score, 5, 19, "%d", game->line);
  mvwprintw(score, 6, 2, "Level");
  mvwprintw(score, 6, 19, "%d", game->level);
  mvwprintw(score, 8, 2, "Timer:");
  if (game->time_sec > 9)
    mvwprintw(score, 8, 18, "%d : %d", game->time_min, game->time_sec);
  else
    mvwprintw(score, 8, 18, "%d : 0%d", game->time_min, game->time_sec);
}
