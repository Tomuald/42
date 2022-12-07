NAME	=	program

HEAD	=	Base.class.hpp	\
			A.class.hpp		\
			B.class.hpp		\
			C.class.hpp		\

SRCS	=	main.cpp	\
			Base.class.cpp

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
