NAME = push_swap

NAME_BONUS = checker

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS =  srcs/error_manager.c \
		srcs/init_stack.c \
		srcs/push_swap.c \
		srcs/sort_size_three.c \
		srcs/sort_stack.c \
		srcs/sort_utils.c \
		srcs/sort_utils2.c \
		srcs/stack_utils.c \
		commands/push.c \
		commands/rev_rotate.c \
		commands/rotate.c \
		commands/swap.c \

SRCS_BONUS = bonus/bonus.c \
			 srcs/error_manager.c \
			 commands/push.c \
			 commands/rev_rotate.c \
			 commands/rotate.c \
			 commands/swap.c \
			 srcs/init_stack.c \
			 srcs/sort_utils.c \
			 srcs/sort_utils2.c \
			 srcs/stack_utils.c \

OBJS    = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}
LIBFT_DIR = libft
LIBFT_A = libft/libft.a

_CLEAR      = \033[0K\r\c
_OK         = [\033[32mOK\033[0m]


all : $(LIBFT_A) $(NAME)

${NAME}: ${OBJS} $(LIBFT_A) 
	@${CC} ${CFLAGS} -g3 -I include -I libft/ -o $@ $^ -Llibft/ -lft
	@echo "$(_OK) $(NAME) compiled"

%.o: %.c  include/push_swap.h include/commands.h libft/libft.h 
	@echo "[..] $(NAME_SHORT)... compiling $*.c\r\c"
	@${CC} ${CFLAGS} -g3 -Iinclude -Ilibft/ -c $< -o $@
	@echo "$(_CLEAR)"

$(LIBFT_A): libft/libft.h 
	@echo "[..] libft... compiling \r\c"
	@$(MAKE) -C $(LIBFT_DIR) -s
	@echo "$(_CLEAR)"

bonus : $(OBJS_BONUS) $(LIBFT_A)
	${CC} ${CFLAGS} -g3 -Iinclude -Ilibft/ -o $(NAME_BONUS) $(OBJS_BONUS) -Llibft/ -lft
	@echo "$(_OK) $(NAME_BONUS) compiled"

clean :
		@$(MAKE) -C $(LIBFT_DIR) clean -s
		@$(RM) $(OBJS)
		@$(RM) $(OBJS_BONUS)

fclean : clean
		@$(MAKE) -C $(LIBFT_DIR) fclean -s
		@$(RM) $(NAME)
		@$(RM) $(NAME_BONUS)

re : fclean all

.PHONY: all clean fclean re libft bonus

