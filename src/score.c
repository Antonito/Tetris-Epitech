/*
** score.c for score in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Feb 23 14:53:09 2016 Arthur ARNAUD
** Last update Thu Feb 25 17:16:25 2016 Arthur ARNAUD
*/

#include "tetris.h"

void	display_score(WINDOW *score, t_game *game)
{
  mvwprintw(score, 2, 2, "High Score");
  mvwprintw(score, 2, 22, "%d", game->highscore);
  mvwprintw(score, 3, 2, "Score");
  mvwprintw(score, 3, 22, "%d", game->score);
  mvwprintw(score, 5, 2, "Lines");
  mvwprintw(score, 5, 22, "%d", game->lines);
  mvwprintw(score, 6, 2, "Level");
  mvwprintw(score, 6, 22, "%d", game->level);
  mvwprintw(score, 8, 2, "Timer:");
  mvwprintw(score, 8, 18, "%d : %d", game->time_min, game->time_sec);
}
