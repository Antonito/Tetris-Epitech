##
## Makefile for Tetris in /PSU_2015_tetris
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Tue Feb 23 14:08:31 2016 Antoine Baché
## Last update Tue Mar  8 21:58:12 2016 Antoine Baché
##

DEBUG=			yes

SRC_PREFIX=		src/

SRC_FILES=		main.c			\
			get_next_line.c		\
			load.c			\
			add_tetri.c		\
			score.c			\
			board.c			\
			my_memset.c		\
			init_game.c		\
			display.c		\
			my_getnbr.c		\
			my_strlen.c		\
			my_strncmp.c		\
			my_strndup.c		\
			my_str_to_wordtab.c	\
			interface.c		\
			check_file.c		\
			check_args.c		\
			add_dir_name.c		\
			getTerm.c		\
			select.c		\
			errors.c		\
			free.c			\
			debug.c			\
			my_put_nbr.c		\
			isOver.c		\
			args/debug.c		\
			args/help.c		\
			args/keysLR.c		\
			args/keysQP.c		\
			args/keysTD.c		\
			args/level.c		\
			args/next.c		\
			args/size.c		\
			events/game.c		\
			events/move.c

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

NAME=			tetris

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

CC=			gcc

RM=			rm -f

LIB=			-lncurses

OBJ=			$(SRC:.c=.o)

$(NAME):	$(OBJ)
ifeq ($(DEBUG), yes)
	@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ ";
	@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|";
	@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  ";
	@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ ";
	@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|";
	@echo "                                                           ";
endif
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled game"
	@$(CC) $(OBJ) -o $(NAME) $(LIB)

%.o:	%.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
