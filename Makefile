##
## EPITECH PROJECT, 2023
## style
## File description:
## Makefile
##

NAME		:=	style

DIR			:=	./src/
SRC			:=	$(addprefix $(lastword $(DIR)),\
				style.c		\
				)

ROOT_OBJ	:=	./.obj/
DIR_OBJ		:=	$(addprefix $(ROOT_OBJ), $(DIR))
OBJ			:=	$(patsubst %.c, $(ROOT_OBJ)%.o, $(SRC))

LIB			:=	lib
MAKE		:=	make -s --jobs=9

RM			:=	rm -f

CC			:=	gcc
CFLAGS		:=	-I./include/ -Wall -Wextra -g
LDFLAGS		:=	-L./lib/
LDLIBS		:=	-lice

all:				$(DIR_OBJ) $(NAME)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(ROOT_OBJ)%.o:		%.c
	@$(CC) $(CFLAGS) -c $< -o $@\
	&& printf "\033[32m[OK]\033[0m %s\n" $<\
	|| printf "\033[31m[KO]\033[0m %s\n" $<

$(NAME):			$(OBJ)
	@$(MAKE) -C $(LIB)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)\
	&& printf "\033[32m[SUCCES]\033[0m %s\n" $@\
	|| printf "\033[31m[ERROR]\033[0m %s\n" $@

clean:
	@$(MAKE) clean -C $(LIB)
	@[ -d $(ROOT_OBJ) ]\
	&& $(RM) $(ROOT_OBJ)\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(ROOT_OBJ) || true

fclean:				clean
	@$(MAKE) fclean -C $(LIB)
	@[ -f $(NAME) ]\
 	&& $(RM) $(NAME)\
 	&& printf "\033[31m[DELETED]\033[0m %s\n" $(NAME) || true

re:					fclean all

.PHONY:				all clean fclean re

.SILENT:			all clean fclean re
