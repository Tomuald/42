NAME	=	program

SRCS	=	Zombie.cpp	\
			zombieHorde.cpp

OBJS	=	${SRCS:.cpp=.o}

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	g++

RM		=	rm -Rf

all:		${NAME}

${NAME}:	${SRCS} main.cpp
			${CC} ${CFLAGS} main.cpp ${SRCS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
