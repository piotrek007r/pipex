CC = gcc
CFLAGS = -Wall -Werror -Wextra 

SRCS = $(wildcard *.c libft/*.c ft_printf/*.c)
OBJS = $(SRCS:.c=.o)
NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

%.o : %.c 
	$(CC) $(CFLAGS) -I./libft -I./ft_printf -c $< -o $@ 

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re