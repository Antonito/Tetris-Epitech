/*
** score.c for score in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 14:53:09 2016 Arthur ARNAUD
** Last update Mon Mar 14 15:44:17 2016 Arthur ARNAUD
*/

#include "tetris.h"

void	display_score(WINDOW *score, t_game *game)
{
  mvwprintw(score, 2, 2, "High Score");
  mvwprintw(score, 2, 22, "%d", game->highscore);
  mvwprintw(score, 3, 2, "Score");
  mvwprintw(score, 3, 22, "%d", game->score);
  mvwprintw(score, 5, 2, "Lines");
  mvwprintw(score, 5, 22, "%d", game->line);
  mvwprintw(score, 6, 2, "Level");
  mvwprintw(score, 6, 22, "%d", game->level);
  mvwprintw(score, 8, 2, "Timer:");
  if (game->time_sec > 9)
    mvwprintw(score, 8, 18, "%d : %d", game->time_min, game->time_sec);
  else
    mvwprintw(score, 8, 18, "%d : 0%d", game->time_min, game->time_sec);
}
