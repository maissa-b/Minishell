# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/14 20:41:38 by maissa-b          #+#    #+#              #
#    Updated: 2016/02/13 16:18:56 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = ft_minishell.c ft_binaries.c ft_builtin_cd.c ft_builtin_env.c \
	ft_builtin_exit.c ft_builtin_setenv.c ft_builtin_unsetenv.c ft_builtins.c \
	ft_check_errors.c ft_clear_list.c ft_env_utils.c ft_list_env.c ft_parse.c \
	ft_tools.c ft_builtin_export.c ft_opts.c

OBJ = $(SRC:%.c=%.o)
INCLUDE = ft_minishell.h
LIB = libft/
LIB_FLAGS = libft/bin/libft.a
SRC_DIR = srcs/
OBJ_DIR = objs/
INCLIB_DIR	= libft/includes/
INC_DIR = includes/

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
INCS = $(addprefix $(INC_DIR), $(HEADER))

.SILENT:

all: create_repos compile_lib send_mesage $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft/bin -lft
	printf "\033[32m\n\n$(NAME) created.\n\033[m"

create_repos:
	mkdir -p $(OBJ_DIR)

send_mesage:
	printf "\033[1m_______________________________________________________________________\n\n\033[m"
	printf "\033[33mCompiling $(NAME) : \n\033[m"

compile_lib:
	make -C $(LIB)

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(INCLIB_DIR) -o $@ -c $<
	printf "\033[1;34m. \033[m"

clean:
	Make -C libft/ clean
	rm -rf $(OBJS)
	rm -rf $(OBJ_DIR)
	echo "\033[31mRemoving objs in $(NAME)\033[m"

fclean:	clean
	Make -C libft/ fclean
	rm -rf $(NAME)
	echo "\033[31mRemoving $(NAME)\033[m"

re: fclean all

header:
	echo "\033[32mCheck header.\033[m"
	echo "\033[1mBY\033[m"
	grep "By" $(INCS) $(SRCS) | cut -c1-70
	echo "\033[1mCREATED\033[m"
	grep "Created" $(INCS) $(SRCS) | cut -c1-70

user:
	echo "\033[32mCheck fichier auteur.\033[m"
	cat -e auteur
	whoami | cat -e

normi_lib:
	make -C libft/ normi

normi_sh:
	norminette $(SRC_DIR) $(INC_DIR)
	echo "\033[32m$(NAME) : Norminette done.\033[0m"
