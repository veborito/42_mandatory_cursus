NAME		:= fdf

LIB			:= ft
LIB_TARGET	:=		\
	libft/libft.a	\

INCS		:= 		\
	include			\
	libft/include	\

SRC_DIR		:= src
SRCS		:=			\
	main.c				\
	utils/list.c	\
	utils/tabs.c	\
	utils/draw.c	\
	utils/str.c	\
	utils/map.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS 		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

#---------------------- MLX ---------------------------
DIR_MLX 	:= mlx/
MLX_LNK		:= -L $(DIR_MLX) -l mlx -framework OpenGL -framework AppKit

MLX_INC 	:= -I $(DIR_MLX)
MLX 		:=	$(DIR_MLX)libmlx.a
#------------------------------------------------------

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I , $(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L, $(dir $(LIB_TARGET)))
LDLIB		:= $(addprefix -l, $(LIB))

RM 			:= rm -rf
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D) 

all: $(NAME) 

$(NAME): $(OBJS) $(LIB_TARGET) $(MLX)
	$(CC) $(LDFLAGS) $(MLX_LNK) $(OBJS) $(LDLIB) -lm -o $(NAME)
	$(info CREATED $(NAME))

$(LIB_TARGET):
	$(MAKE) -C $(@D)

$(MLX):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(MLX_INC) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(MAKE) -C $(dir $(LIB_TARGET)) clean
	$(RM) $(OBJS) $(DEPS) $(BUILD_DIR)
	$(info CLEANING...)

mlxclean:
	$(MAKE) -C $(DIR_MLX) clean

fclean:	clean mlxclean
	$(MAKE) -C $(dir $(LIB_TARGET)) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:	all clean fclean re
.SILENT:
