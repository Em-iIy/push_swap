#----------------------------------------Files
FILES_SRCS =	push_swap.c \
				error_exit.c \
				parse_input.c \
				parse_input_binary.c \
				node_utils.c \
				op_push.c \
				op_swap.c \
				op_rotate.c \
				op_rrotate.c \
				op_choose.c \

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
# CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g
INC = -Iinc

#----------------------------------------Name
NAME = push_swap

#----------------------------------------Making
all: $(NAME)

$(NAME): $(DIR_OBJS) $(LIBFT) $(OBJS) 
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

$(DIR_OBJS)%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

#------------------------------Directories
$(DIR_OBJS):
	@mkdir -p $@

#------------------------------Libraries
$(LIBFT):
	@echo "Compiling libft..."
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

