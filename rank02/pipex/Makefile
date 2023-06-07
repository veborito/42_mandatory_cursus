NAME		:= pipex

LIB			:= ft
LIB_TARGET	:=		\
	libft/libft.a	\

INCS		:= 		\
	include			\
	libft/include	\

SRC_DIR		:= src
SRCS		:=		\
	main.c			\
	error.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS 		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

#------------------------------------------------------

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I , $(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L, $(dir $(LIB_TARGET))) -fsanitize=address -g3
LDLIB		:= $(addprefix -l, $(LIB))

RM 			:= rm -rf
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D) 

all: $(NAME) 

$(NAME): $(OBJS) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIB) -o $(NAME)
	$(info CREATED $(NAME))

$(LIB_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(MAKE) -C $(dir $(LIB_TARGET)) clean
	$(RM) $(OBJS) $(DEPS) $(BUILD_DIR)
	$(info CLEANING...)

fclean:	clean
	$(MAKE) -C $(dir $(LIB_TARGET)) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:	all clean fclean re
.SILENT:
