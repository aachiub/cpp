NAME = yellowpages

SRC = yellowpages.cpp Contact.class.cpp Phonebook.class.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) 

$(NAME) : $(LIB) $(OBJ)
	clang++ -o $(NAME) $(OBJ)

%.o : %.c
	clang++ $(CFLAGS) -o $@ $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all