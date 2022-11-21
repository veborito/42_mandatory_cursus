SRC = ft_characters ft_flags ft_hexa_pointer ft_numbers

MAIN = ft_printf.c

NAME = libftprintf.a

SRCS = $(addsuffix .c, $(addprefix src/, $(SRC)))

OBJS = $(SRCS:.c=.o)

OBJM = $(MAIN:.c=.o)

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = ar rcs

RM = rm -f

all: affiche $(NAME)

affiche:	
							@echo "                                \n\
      _____   _________________            _____        _____    ____  _____   ______   _________________       _____ \n\
 ____|\    \ /                 \       ___|\    \   ___|\    \  |    ||\    \ |\     \ /                 \ ____|\    \ \n\
|    | \    \\______     ______/      |    |\    \ |    |\    \ |    | \\    \| \     \\______     ______/|    | \    \ \\n\
|    |______/   \( /    /  )/         |    | |    ||    | |    ||    |  \|    \  \     |  \( /    /  )/   |    |______/ \n\
|    |---- \       |   |              |    |/____/||    |/____/ |    |   |     \  |    |     |   |        |    |----\ \n\
|    |_____/       |   |              |    ||    |||    |\    \ |    |   |      \ |    |     |   |        |    |_____/ \n\
|    |            /   //              |    ||____|/|    | |    ||    |   |    |\ \|    |    /   //        |    | \n\
|____|           /___//               |____|       |____| |____||____|   |____||\_____/|   /___//         |____| \n\
|    |          |    |                |    |       |    | |    ||    |   |    |/ \|   ||  |    |          |    | \n\
|____|          |____|                |____|       |____| |____||____|   |____|   |___|/  |____|          |____| \n\
  )/              \(                    \(           \(     )/    \(       \(       )/      \(              )/ \n "
                                                                                                                       
							@echo "By : bverdeci\n"

$(NAME): $(OBJM) $(OBJS)
							@make -C libft
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

