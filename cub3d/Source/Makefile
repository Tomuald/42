SRCS	=	main.c utils.c parse.c keypress.c

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx-linux -O3 -c $< -o $@

OBJS = ${SRCS:.c=.o}

NAME = project.a

PROGRAM = program

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -Rf

MLX_MAC = -Lmlx-mac -lmlx -framework OpenGL -framework AppKit

MLX_LIN = -I./mlx-linux -L./mlx-linux -lmlx -L. -lX11 -lXext -lm -lbsd

OS_NAME := $(shell uname -s | tr A-Z a-z)

	ifeq ($(OS_NAME), linux)
	MLX = ${MLX_LIN}
	MLX_FOL = mlx-linux
else
	MLX = ${MLX_MAC}
	MLX_FOL = mlx-mac
endif

${NAME}: ${OBJS} main.c
	make -C libft/
	cp libft/libft.a lib${NAME}
	ar rcs lib${NAME} ${OBJS}
	make -C ${MLX_FOL}
	${CC} ${CFLAGS} main.c -L. -l$(basename ${NAME}) ${MLX} -o ${PROGRAM}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	@make fclean -C libft/
	@make clean -C ${MLX_FOL}/
	${RM} lib${NAME} ${PROGRAM}

re: fclean all

.PHONY: all bonus clean fclean re
