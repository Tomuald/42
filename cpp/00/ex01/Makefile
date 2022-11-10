NAME	=	phonebook

SRCS	=	contact.class.cpp \
			phonebook.class.cpp

OBJS	=	${SRCS:.cpp=.o}

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	g++

RM		=	rm -Rf

all:		${NAME}

${NAME}:	${SRCS}
			${CC} ${CFLAGS} main.cpp ${SRCS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
