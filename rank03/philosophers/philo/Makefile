NAME		:= philo

INCS		:= 		\
	include			\

SRC_DIR		:= src
SRCS		:=			\
	main.c				\
	utils/write_error.c \
	utils/numbers.c 	\
	utils/philos.c 		\
	utils/init.c 		\

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS 		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= gcc -fsanitize=address -g3
CFLAGS		:= -Wall -Wextra -Werror -pthread
CPPFLAGS	:= $(addprefix -I , $(INCS)) -MMD -MP
 
RM 			:= rm -rf
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D) 

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS) $(BUILD_DIR)
	$(info CLEANING...)

fclean:	clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:	all clean fclean re
.SILENT:
