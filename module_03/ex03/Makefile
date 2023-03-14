SOURCES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
NAME = main
OBJS = $(SOURCES:.cpp=.o)
CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98 -Wno-shadow

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
