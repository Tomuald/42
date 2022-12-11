NAME	=	program

HEAD	=	templates.hpp

SRCS	=	main.cpp

OBJS	=	${SRCS:.cpp=.o}

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

RM		=	rm -Rf

all:		${NAME}

${NAME}:	${SRCS} ${HEAD}
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
