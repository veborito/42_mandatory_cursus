NAME		:= libft.a
SRC_DIR		:= src
SRCS		:= \
	basic/ft_isalpha.c					\
	basic/ft_isdigit.c					\
	basic/ft_isalnum.c					\
	basic/ft_isascii.c					\
	basic/ft_isprint.c					\
	basic/ft_atoi.c						\
	basic/ft_bzero.c					\
	memory/ft_memset.c					\
	memory/ft_memcpy.c					\
	memory/ft_memmove.c					\
	memory/ft_memchr.c 					\
	memory/ft_memcmp.c					\
	memory/ft_calloc.c					\
	str/ft_strlen.c						\
	str/ft_strlcpy.c					\
	str/ft_strlcat.c					\
	str/ft_toupper.c					\
	str/ft_tolower.c					\
	str/ft_strchr.c						\
	str/ft_strrchr.c					\
	str/ft_strncmp.c					\
	str/ft_strnstr.c					\
	str/ft_strdup.c						\
	str/ft_substr.c						\
	str/ft_strjoin.c					\
	str/ft_strtrim.c					\
	str/ft_split.c						\
	str/ft_itoa.c						\
	str/ft_strmapi.c					\
	str/ft_striteri.c					\
	fd/ft_putchar_fd.c					\
	fd/ft_putstr_fd.c					\
	fd/ft_putendl_fd.c					\
	fd/ft_putnbr_fd.c					\
	linked_list/ft_lstnew_bonus.c		\
	linked_list/ft_lstadd_front_bonus.c	\
	linked_list/ft_lstsize_bonus.c		\
	linked_list/ft_lstlast_bonus.c		\
	linked_list/ft_lstadd_back_bonus.c	\
	printf/ft_printf.c					\
	printf/ft_characters.c				\
	printf/ft_hexa_pointer.c			\
	printf/ft_numbers.c					\
	get_next_line/get_next_line.c		\
	get_next_line/get_next_line_utils.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS 		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= gcc 
CFLAGS		:= -g -Wall -Wextra -Werror
CPPFLAGS	:= -MMD -MP -I include
AR			:= ar
ARFLAGS		:= -r -c -s

RM 			:= rm -rf
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D) 

LIB = ar rcs

all: $(NAME) 

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS) $(BUILD_DIR)

fclean:	clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:	all clean fclean re
.SILENT: