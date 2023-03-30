SOURCES = ScalarConverter.cpp
NAME = main
TEST = test

MAIN = main.cpp
MAIN_OBJ = ${MAIN:.cpp=.o}

MAIN_T = tests.cpp Test.cpp
MAIN_TOBJ = ${MAIN_T:.cpp=.o}

OBJS = $(SOURCES:.cpp=.o)

CC = c++
FLAGS := -Werror -Wextra -Wall -std=c++98 -g
DEBUG = -D DEBUG=0

all: ${NAME}

tests:	debug ${TEST}
		./${TEST}
		
debug:
		${eval FLAGS := ${FLAGS} ${DEBUG}}

%.o: %.cpp
		${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS} ${MAIN_OBJ}
		${CC} ${FLAGS} ${OBJS} ${MAIN_OBJ} -o ${NAME}
		
${TEST}: ${OBJS} ${MAIN_TOBJ}
		${CC} ${FLAGS} ${OBJS} ${MAIN_TOBJ} -o ${TEST}

clean:
		rm -f ${OBJS} ${MAIN_OBJ} ${MAIN_TOBJ}

fclean: clean
		rm -f ${NAME} ${TEST}

re: fclean all

ret: fclean tests

