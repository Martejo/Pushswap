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

SRCS_BONUS = checker/checker.c \
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
LIBFT   = make all -C libft/




all : $(NAME)

%.o: %.c  include/push_swap.h include/commands.h
	@${CC} ${CFLAGS} -g3 -Iinclude -Ilibft/ -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -g3 -Iinclude -Ilibft/ -o $@ $^ -Llibft/ -lft

bonus : $(OBJS_BONUS)
		${CC} ${CFLAGS} -g3 -Iinclude -Ilibft/ -o $@ $^ -Llibft/ -lft



fclean : clean
		$(RM) $(NAME)
		@make -s fclean -C libft/

clean :
		$(RM) $(OBJS)

re : fclean all

libft:
		@make -s all -C libft/

.PHONY: all clean fclean re libft

