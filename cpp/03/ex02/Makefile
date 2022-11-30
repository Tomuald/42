NAME	=	program

HEAD	=	ClapTrap.hpp \
			FragTrap.hpp

SRCS	=	ClapTrap.cpp \
			FragTrap.cpp

OBJS	=	${SRCS:.cpp=.o}

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

RM		=	rm -Rf

all:		${NAME}

${NAME}:	${SRCS} ${HEAD} main.cpp
			${CC} ${CFLAGS} main.cpp ${SRCS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
