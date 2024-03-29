#----------------------------------------Name
NAME = push_swap

# ---------------------------------------Colors
ESC = \033
NORMAL = $(ESC)[m\017
BOLD = $(ESC)[1m
GREEN = $(ESC)[0;92m$(BOLD)
BLUE = $(ESC)[0;94m$(BOLD)

#----------------------------------------Files
FILES_SRCS =	push_swap.c \
				error_exit.c \
				parse_input.c \
				node_utils.c \
				op_push.c \
				op_swap.c \
				op_rotate.c \
				op_rrotate.c \
				op_choose.c \
				sort_short.c \
				sort_long.c \
				is_sorted.c \
				sorting.c \

FILES_OBJS = $(FILES_SRCS:.c=.o)

#----------------------------------------Directories
DIR_SRCS = ./srcs/
DIR_OBJS = ./objs/
DIR_LIBFT =./libft/
vpath %.c $(DIR_SRCS)

#----------------------------------------Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

#----------------------------------------Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

#----------------------------------------Libraries
LIBFT = $(DIR_LIBFT)libft.a

#----------------------------------------Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -g
INC = -Iinc

#----------------------------------------Making
all: $(NAME)

$(NAME): $(DIR_OBJS) $(LIBFT) $(OBJS) 
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)push_swap made$(NORMAL)"

$(DIR_OBJS)%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

#------------------------------Directories
$(DIR_OBJS):
	@mkdir -p $@

#------------------------------Libraries
$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(NORMAL)"
	@make -C $(DIR_LIBFT)

#----------------------------------------Cleaning
clean:
	@make -C $(DIR_LIBFT) clean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

fclean_all: fclean
	@make -C $(DIR_LIBFT) fclean

re: fclean all

re_all: fclean_all all

.PHONY: all clean fclean fclean_all re re_all