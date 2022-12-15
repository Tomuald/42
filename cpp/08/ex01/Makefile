NAME	=	program

HEAD	=	Span.class.hpp

SRCS	=	Span.class.cpp

OBJS	=	${SRCS:.cpp=.o}

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

RM		=	rm -Rf

all:		${NAME}

${NAME}:	${SRCS} ${HEAD} main.cpp
			${CC} ${CFLAGS} ${SRCS} main.cpp -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
