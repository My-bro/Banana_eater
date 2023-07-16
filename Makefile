## EPITECH PROJECT, 2022
## BSQ Project
## File description:
## Makefile

SRC = 	main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = prog

CXX = g++

CPPFLAGS        =    	-iquote includes

LDFLAGS =

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) *~

fclean: clean
	rm -f $(NAME)

re: fclean all
