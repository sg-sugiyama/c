NAME		 := swap
CC       := gcc
CFLAGS   := -Wall -Wextra -Werror
SRCDIR   := ./srcs/
SRCS     := $(wildcard $(SRCDIR)*.c) $(wildcard $(SRCDIR)*/*.c)
OBJS     := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re