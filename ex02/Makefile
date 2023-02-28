SOURCES = tests.cpp Account.cpp
NAME = account
OBJS = $(SOURCES:.cpp=.o)
CC = c++
FLAGS =-std=c++98

all: ${NAME}

%.o: %.cpp
		${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

teste:
		echo ${OBJ}
