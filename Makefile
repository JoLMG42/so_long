# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 17:18:16 by jtaravel          #+#    #+#              #
#    Updated: 2022/01/28 17:13:56 by jtaravel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./classics/ft_split.c ./classics/ft_strlen.c ./classics/ft_putstr.c \
	./classics/ft_itoa.c \
	./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
	./srcs/ft_parsing.c ./srcs/ft_recup_map.c ./srcs/ft_check_map.c so_long.c \
	./srcs/ft_free.c ./srcs/ft_info_map.c ./srcs/ft_moves.c ./srcs/ft_display_map.c \
	./srcs/ft_game.c ./srcs/ft_recup_img.c \


OBJS =	${SRCS:.c=.o}

HEADERS =	includes

NAME =	so_long

MINILIBX_PATH = ./mlx/
MINILIBX = ${MINILIBX_PATH}libmlx.a

NAME_BONUS =	checker

CC =	gcc

MLXFLAGS = -L. -lXext -L. -lX11

RM =	rm -f

CFLAGS =	-Wall -Wextra -Werror -g3

.c.o:
		${CC} ${CFLAGS} -I${HEADERS} -c $< -o ${<:.c=.o}


${NAME}:	${OBJS} ${MINILIBX}
		${CC} ${CFLAGS} ${OBJS} ${MINILIBX} ${MLXFLAGS} -o ${NAME}

all:		${NAME}

${MINILIBX}:	
	make -C ${MINILIBX_PATH}

clean:
		${RM} ${OBJS}
		make -C ${MINILIBX_PATH} clean

fclean:		clean
		${RM} ${NAME} 

re:		fclean all

.PHONY:		all clean flcean re
