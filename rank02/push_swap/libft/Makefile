FT = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	 ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
	 ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	 ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c 

SRC = ft_characters ft_hexa_pointer ft_numbers

MAIN = ft_printf.c

SRCS = $(addsuffix .c, $(addprefix src/, $(SRC)))

OBJSRC = $(SRCS:.c=.o)

OBJM = $(MAIN:.c=.o)

OBJS = $(FT:.c=.o)

BOBJS =$(BONUS:.c=.o)
 
CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

RM = rm -f

LIB = ar rcs

all: $(NAME) 

$(NAME): $(OBJS) $(OBJSRC) $(OBJM)
					$(LIB) $(NAME) $(OBJS) $(OBJSRC) $(OBJM)
bonus: $(NAME) $(BOBJS)
					$(LIB) $(NAME) $(BOBJS)		
clean:
					$(RM) $(OBJS) $(BOBJS) $(OBJSRC) $(OBJM)
fclean:	clean
					$(RM) $(NAME)
re:	fclean	all

.PHONY:	all re clean fclean bonus
