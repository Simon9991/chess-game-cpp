# Compiler
CC = g++

# Flags
LDFLAGS = -Wall -Wextra -g -std=c++20
INC = -I include

# Executable
NAME = evaluate

# Files
SRC = $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)

# Object files
OBJ = $(SRC:src/%.cpp=src/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

src/%.o: src/%.cpp
	$(CC) -o $@ -c $< $(LDFLAGS) $(INC)

clean:
	find . -name '*.o' -delete

fclean: clean
	rm -rf $(NAME)

re: fclean all

