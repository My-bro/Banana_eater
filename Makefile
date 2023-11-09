## EPITECH PROJECT, 2022
## BSQ Project
## File description:
## Makefile

STR = src/str_function/

LINK = src/linked_list_function/

PARS = src/parsing_function/

ERROR = src/error_handling/

WRITE = src/file_writting/

SRC = 	$(STR)my_strlen.cpp\
		$(STR)my_strncpy.cpp\
		$(STR)is_inside.cpp\
		$(STR)my_strcmp.cpp\
		$(STR)patern_is_inside.cpp\
		$(STR)how_many_char_inside.cpp\
		$(STR)strconcat.cpp\
		$(LINK)add_node.cpp\
		$(LINK)make_patern_linked_list.cpp\
		$(LINK)make_lines_array_linked.cpp\
		$(PARS)extract_function.cpp\
		$(PARS)file_opener.cpp\
		$(ERROR)error_hand.cpp\
		$(WRITE)file_writting.cpp\
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
