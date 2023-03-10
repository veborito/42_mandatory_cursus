NAME := push_swap

SRC = ft_characters ft_hexa_pointer ft_numbers

SRCS = $(addsuffix .c, $(addprefix src/, $(SRC)))

OBJS = $(SRCS:.c=.o)

OBJM = $(MAIN:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = ar rcs

RM = rm -f

all:
							@make -C libft
							@cp libft/libft.a .
							@mv libft.a $(NAME)
							$(LIB) $(NAME) $(OBJS) $(OBJM)
clean:
							@echo "           																   \n\
					              																			   \n\
					              																			   \n\
					              									CLEANING...								   \n\
					              																			   \n\
					              																			   \n\
					              																			   \n "
							@make clean -C libft
							$(RM) $(OBJS) $(OBJM)
fclean: clean
							$(RM) libft/libft.a
							$(RM) $(NAME)

re: fclean all	
							@echo "           																   \n\
					              																			   \n\
					              																			   \n\
					              									ALL DONE !								   \n\
					              																			   \n\
					              																			   \n\
					              																			   \n "

						
.PHONY: all clean fclean re

