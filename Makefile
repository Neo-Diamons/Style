##
## EPITECH PROJECT, 2023
## Style
## File description:
## Makefile
##

NAME		:=	style

DIR_SRC		:=	src/

DIR			:=	$(DIR_SRC)
SRC			:=	$(addprefix $(DIR),\
				main.c				\
				style.c				\
				get_file.c			\
				strsplit.c			\
				destroy.c			\
				)

DIR_BUILD	:=	build/

ROOT_OBJ	:=	$(addprefix $(DIR_BUILD), obj/$(NAME)/)
DIR_OBJ		:=	$(addprefix $(ROOT_OBJ), $(DIR))
OBJ			:=	$(patsubst %.c, $(ROOT_OBJ)%.o, $(SRC))

RM			:=	rm -rf

CC			:=	gcc
CFLAGS		:=	-I./include/ -Wall -Wextra

DEBUG		:=	-g
D_ROOT_OBJ	:=	$(addprefix $(DIR_BUILD), debug/obj/$(NAME)/)
D_OBJ		:=	$(patsubst %.c, $(D_ROOT_OBJ)%.o, $(SRC))
DIR_OBJ		+=	$(addprefix $(D_ROOT_OBJ), $(DIR))

all:				$(DIR_OBJ) $(NAME)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)\
	&& printf "\033[93m[CREATED]\033[0m %s\n" $(DIR_OBJ)\
	|| printf "\033[31m[ERROR]\033[0m %s\n" $(DIR_OBJ)

$(ROOT_OBJ)%.o:		%.c
	@$(CC) $(CFLAGS) -c $< -o $@\
	&& printf "\033[32m[OK]\033[0m %s\n" $<\
	|| printf "\033[31m[KO]\033[0m %s\n" $<

$(D_ROOT_OBJ)%.o:		%.c
	@$(CC) $(CFLAGS) -c $< -o $@\
	&& printf "\033[32m[OK]\033[0m %s\n" $<\
	|| printf "\033[31m[KO]\033[0m %s\n" $<

$(NAME):			$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDLIBS)\
	&& printf "\033[32m[SUCCESS]\033[0m %s\n" $@\
	|| printf "\033[31m[ERROR]\033[0m %s\n" $@

debug:				CFLAGS += $(DEBUG)
debug:				OBJ := $(D_OBJ)
debug:				$(DIR_OBJ) $(D_OBJ) $(NAME)

clean:
	@[ -d $(DIR_BUILD) ]\
	&& $(RM) $(DIR_BUILD)\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(DIR_BUILD) || true

fclean:				clean
	@[ -f $(NAME) ]\
	&& $(RM) $(NAME)\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(NAME) || true

re:					fclean all

.PHONY:				all debug clean fclean re $(NAME) $(ROOT_OBJ) $(D_ROOT_OBJ)

.SILENT:			all debug clean fclean re $(NAME) $(ROOT_OBJ) $(D_ROOT_OBJ)
