## Makefile with SFML flags

# Compiler

CC = g++

# Compiler flags

CFLAGS = -Wall -Wextra -std=c++11 -g3

# SFML flags

SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Include flags

INCLUDEFLAGS = -I./include

# Executable name

EXEC = chess-game

# Source files

SRC = 	src/main.cpp										\
		src/Classes/Graphical/Image/image.cpp				\
		src/Classes/Graphical/Square/square.cpp				\
		src/Classes/Graphical/Board/board.cpp				\
		src/Classes/Graphical/King/king.cpp					\
		src/Classes/Graphical/Piece/piece.cpp				\
		src/Classes/Input/MouseInput/mouse_input.cpp		\


# Object files

OBJ = $(SRC:.cpp=.o)

# Makefile rules

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(SFMLFLAGS) $(CFLAGS)

%.o: %.cpp

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDEFLAGS)

clean:
	find . -name '*.o' -delete

fclean: clean
	rm -rf $(EXEC)

re: fclean all

.PHONY: all clean fclean re
