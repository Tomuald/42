NAME	=	program

HEAD	=	Bureaucrat.class.hpp	\
			Form.class.hpp			\
			ShrubberyCreationForm.class.hpp \
			RobotomyRequestForm.class.hpp	\
			PresidentialPardonForm.class.hpp	\
			Intern.class.hpp

SRCS	=	Bureaucrat.class.cpp	\
			Form.class.cpp			\
			ShrubberyCreationForm.class.cpp	\
			RobotomyRequestForm.class.cpp	\
			PresidentialPardonForm.class.cpp	\
			Intern.class.cpp				\
			toLower.cpp

OBJS	=	${SRCS:.cpp=.o}

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

CC		=	c++

RM		=	rm -Rf

all:		${NAME}

${NAME}:	${SRCS} main.cpp
			${CC} ${CFLAGS} main.cpp ${SRCS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
