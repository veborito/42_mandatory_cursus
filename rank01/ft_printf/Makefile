CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT = libft

RM = rm -f

LIB = ar rcs

SRC = src/ft_print_char.c src/ft_print_hexa.c src/ft_print_number.c src/ft_print_string.c src/ft_printf.c


OBJS = $(SRC:.c=.o)


.c.o:
					$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
all: $(NAME) 

$(NAME): $(OBJS)
					@make -C $(LIBFT)
					@cp libft/libft.a .
					@mv libft.a $(NAME)
					$(LIB) $(NAME) $(OBJS)
clean:
					$(RM) $(OBJ) $(OBJS)
					@make clean -C $(LIBFT)
fclean:	clean
					$(RM) $(NAME)
					$(RM) $(LIBFT)/libft.a
re:	fclean	all

.PHONY:	all re clean fclean
