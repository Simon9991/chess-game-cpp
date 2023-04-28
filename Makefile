## Makefile with SFML flags

# Compiler

CC = g++

# Compiler flags

CFLAGS = -Wall -Wextra -std=c++14 -g3

# SFML flags

SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Include flags

INCLUDEFLAGS = -I./include

# Executable name

EXEC = chess-game

# Engine executable name

ENGINE_EXEC = chess-engine

# Source files

SRC = 	src/main.cpp										\
		src/Classes/Graphical/Image/image.cpp				\
		src/Classes/Graphical/Square/square.cpp				\
		src/Classes/Graphical/Board/board.cpp				\
		src/Classes/Graphical/King/king.cpp					\
		src/Classes/Graphical/Moves/moves.cpp				\
		src/Classes/Graphical/Piece/piece.cpp				\
		src/Classes/GameEngine/Movement/movement.cpp		\
		src/Classes/Input/MouseInput/mouse_input.cpp		\


# Engine files

ENGINE_SRC	=	src/Engine/main.cpp										\
				src/Engine/Classes/MemoryBoard/memoryBoard.cpp			\
				src/Engine/Classes/Move/EngineMove.cpp					\
				src/Engine/Classes/MoveGenerator/MoveGenerator.cpp		\
				src/Engine/Classes/MoveEvaluator/MoveEvaluator.cpp		\
				src/Engine/Classes/Search/Search.cpp					\




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

engine:
	$(CC) -o $(ENGINE_EXEC) $(ENGINE_SRC) $(SFMLFLAGS) $(CFLAGS)

re-engine: fclean engine

.PHONY: all clean fclean re
