NAME = testpony

SRC = Pony.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror

all : $(NAME) 

$(NAME) : $(OBJ)
	clang++ -o $(NAME) $(OBJ)

%.o : %.cpp
	clang++ $(CPPFLAGS) -o $@ $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all