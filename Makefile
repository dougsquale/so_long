CC			=	gcc

FLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

SRCS		=	srcs/main.c				\
				srcs/map_parsing.c		\
				srcs/my_free.c			\
				srcs/draw_map.c			\
				srcs/game_rules.c		\
				srcs/utils.c			\
				srcs/movement.c

BONUS_SRCS	=	bonus/srcs/main.c			\
				bonus/srcs/map_parsing.c	\
				bonus/srcs/my_free.c		\
				bonus/srcs/draw_map.c		\
				bonus/srcs/game_rules.c		\
				bonus/srcs/utils.c			\
				bonus/srcs/movement.c		\
				bonus/srcs/mob_movement.c

OBJS		=	${SRCS:.c=.o}

BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

LIBFT		=	libft/libft.a

MLX			=	../mlx_linux/libmlx_Linux.a

MLXFLAGS	=	-lX11 -lXext

NAME		=	so_long

BONUS		=	so_long_bonus

all			:	${NAME}

${NAME}		:	${LIBFT} includes/so_long.h ${OBJS}
				${CC} ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME} ${MLX} ${MLXFLAGS}

${LIBFT}	:
				make -C libft/ bonus

bonus		:	${BONUS}

${BONUS}	:	${LIBFT} bonus/includes/so_long.h ${BONUS_OBJS}
				${CC} ${FLAGS} ${BONUS_OBJS} ${LIBFT} -o ${BONUS} ${MLX} ${MLXFLAGS}

.c.o		:
				$(CC) $(FLAGS) -I/usr/include -Imlx_linux -c $< -o $@

clean		:
				${RM} ${OBJS} ${BONUS_OBJS}
				make -C libft/ clean

fclean		:	clean
				${RM} ${NAME} ${BONUS}
				make -C libft/ fclean

re			:	fclean	all

.PHONY		:	all clean fclean re libft bonus