NAME	=	program

HEAD	=	Animal.class.hpp 	\
			Cat.class.hpp		\
			Dog.class.hpp

SRCS	=	Animal.class.cpp	\
			Cat.class.cpp		\
			Dog.class.cpp

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
