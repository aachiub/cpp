NAME = megaphone

SRC = megaphone.cpp

OBJ = megaphone.o

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) 

$(NAME) : $(OBJ)
	clang++ -o $(NAME) $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
