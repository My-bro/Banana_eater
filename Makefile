## EPITECH PROJECT, 2022
## BSQ Project
## File description:
## Makefile

SRC = 	lib/str_function/my_strlen.cpp\
		lib/str_function/my_strncpy.cpp\
		lib/str_function/is_inside.cpp\
		lib/str_function/my_strcmp.cpp\
		lib/str_function/patern_is_inside.cpp\
		lib/str_function/how_many_char_inside.cpp\
		lib/str_function/strconcat.cpp\
		lib/linked_list_function/add_node.cpp\
		src/file_opener.cpp\
		src/error_hand.cpp\
		src/make_patern_linked_list.cpp\
		src/extract_function.cpp\
		main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = banana_eater

CXX = g++

CPPFLAGS        =    	-iquote include

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) *~

fclean: clean
	rm -f $(NAME)

re: fclean all
