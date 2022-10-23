FT_C = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft:strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchrc. ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c 

OBJS = ${FT_C:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

RM = rm -f

LIB = ar rcs

.c.o:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I libft.h

all: ${NAME}

${NAME}: ${OBJS}
					${LIB} ${TARGET} ${OBJS}

clean:
					${RM} ${OBJS}

fclean:	clean
				
					${RM} ${NAME}

re:	fclean all

.PHONY: all re clean fclean

