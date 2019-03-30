NAME = WorldOnFire

SRC = AWeapon.cpp Character.cpp Enemy.cpp PlasmaRifle.cpp PowerFist.cpp \
	RadScorpion.cpp SuperMutant.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -c -Wall -Wextra -Werror

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