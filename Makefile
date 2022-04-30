SRCS =	main.c error_and_free.c

LIB 	=	$(LIB_DIR)libft.a
LIB_DIR =	Libft/

HDRS =	pipex.h Libft/libft.h

OBJS = 	$(SRCS:.c=.o)

NAME = 	pipex

CC = 	gcc
CFLAGS = -Wall -Wextra -Werror -g -o2
RM = 	rm -f

.PHONY: all clean fclean re norm

all:	$(NAME)


$(OBJS):$(HDRS) Makefile

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):$(OBJS)
	@make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	@make -C $(LIB_DIR) clean
	${RM} ${OBJS}

fclean: clean
	${RM} $(LIB)
	${RM} ${NAME}

re: fclean all

norm:
	norminette