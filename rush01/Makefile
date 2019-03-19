CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCS = -I ~/Applications/SFML/include -I includes
LIBS = -l ncurses -L ~/Applications/SFML/lib -l sfml-graphics -l sfml-window -l sfml-system
RPATH = -Wl,-rpath,$$HOME/Applications/SFML/lib

NAME = ft_gkrellm
FILES = main.cpp Monitor.cpp \
		IMonitorModule.cpp Hostname.cpp OS.cpp DateTime.cpp CPU.cpp RAM.cpp Network.cpp\
		IMonitorDisplay.cpp Shell.cpp Graphic.cpp\

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/,$(FILES))

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/,$(FILES:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCS) $(LIBS) $(RPATH) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
