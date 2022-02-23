#----------------------------------------Files
FILES_SRCS = push_swap.c \

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

#----------------------------------------Name
NAME = push_swap

#----------------------------------------Making
all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(DIR_OBJS)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

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

