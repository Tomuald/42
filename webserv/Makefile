NAME	    =	program

HEAD	    =	srcs/configuration/Configuration.class.hpp \
		    srcs/server/Server.class.hpp \

SRCS	    =	srcs/configuration/Configuration.class.cpp \
		    srcs/server/Server.class.cpp \

OBJS	    =	${SRCS:.cpp=.o}

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

CC		=	c++

RM		=	rm -Rf

all:		${NAME}

${NAME}:	${SRCS} srcs/main.cpp
			${CC} ${CFLAGS} srcs/main.cpp ${SRCS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:      clean
		    ${RM} ${NAME}

re:          fclean all

.PHONY: all clean fclean re
