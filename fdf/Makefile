NAME		=	fdf

LIB			=	libfdf.a

SRCS		=	fdf.c map.c render.c utils.c bresenham.c keypress.c matrix.c transform.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

$(NAME):	${OBJS} fdf.h fdf.c
	@make -C libft/ all
	cp libft/libft.a ./${LIB}
	ar rcs ${LIB} ${OBJS}
	${CC} ${CFLAGS} fdf.c -L. -lfdf -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all:	${NAME}

clean:
	${RM} ${OBJS}
	${RM} ${NAME}

fclean:	clean
	@make -C libft/ fclean
	${RM} ${NAME} ${LIB}

re:	fclean all

.PHONY:	all clean fclean re bonus