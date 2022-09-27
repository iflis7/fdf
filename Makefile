NAME = fdf

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

SRCS_PATH = src/
LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

SRCS_FILES = main.c init.c utils.c read_map.c read_utils.c stack_ops.c pixeling.c\
			get_next_line.c get_next_line_utils.c projection.c manage_colors.c\
			ctrl_set.c ctrl_utils.c ctrl_keys.c

# SRCS_FILES = play.c
			 
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)

all: 	$(NAME)
	@echo "BOOM 💥💥💥💥💥 $(NAME) Compiled! 💯 $(DEFAULT)"


$(NAME): $(OBJS)
	-@$(MAKE) -C $(LIBFT_PATH)
	-@$(CC) $(CFLAGS)  -o $@ $^ $(LIBFT) -L. -lmlx -framework OpenGL -framework AppKit

	-@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH)  clean
	@echo "$(YELLOW)Object files deleted!$(DEFAULT)💯"

fclean:	clean
	@$(RM) $(NAME) $(LIBFT) 

re:		fclean all

.PHONY:	all clean libft fclean re

git:
	@git add .
	@git commit -m "$(COMMIT)"
	@echo "\n$(GREEN)$(NAME) Committed!$(DEFAULT)💯"

#COLORS
RED 	= 	\033[1;31m
GREEN 	= 	\033[1;32m
YELLOW 	= 	\033[1;33m
DEFAULT = 	\033[0m

COMMIT = $(shell date "+%d %B %T")
