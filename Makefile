##
## Makefile for Tetris in /PSU_2015_tetris
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Tue Feb 23 14:08:31 2016 Antoine Baché
## Last update Wed Feb 24 12:38:34 2016 Arthur ARNAUD
##

DEBUG=			yes

SRC_PREFIX=		src/

SRC_FILES=		main.c		\
			score.c		\
			display.c	\
			interface.c	\

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
