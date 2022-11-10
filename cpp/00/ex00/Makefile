NAME	=	megaphone

SRCS	=	megaphone.cpp

OBJS	=	${SRCS:.cpp=.o}

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	g++

RM		=	rm -Rf

all:		${NAME}

${NAME}:
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
