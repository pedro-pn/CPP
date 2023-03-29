SOURCES = ScalarConverter.cpp
NAME = main

MAIN = main.cpp
MAIN_OBJ = ${MAIN:.cpp=.o}

MAIN_T = tests.cpp
MAIN_TOBJ = ${MAIN_T:.cpp=.o}
TEST = test
OBJS = $(SOURCES:.cpp=.o)
CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98

all: ${NAME}
	./${NAME}

tests:	${TEST}
		./${TEST}

%.o: %.cpp
		${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS} ${MAIN_OBJ}
		${CC} ${FLAGS} ${OBJS} ${MAIN_OBJ} -o ${NAME}
		
${TEST}: ${OBJS} ${MAIN_TOBJ}
		${CC} ${FLAGS} ${OBJS} ${MAIN_TOBJ} -o ${TEST}

${MAIN_OBJ}: ${MAIN}
		${CC} ${FLAGS} -c $< -o $@
		
${MAIN_TOBJ}: ${MAIN_T}
		${CC} ${FLAGS} -c $< -o $@


clean:
		rm -f ${OBJS} ${MAIN_OBJ} ${MAIN_TOBJ}

fclean: clean
		rm -f ${NAME} ${TEST}

re: fclean all

