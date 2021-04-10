NAME = eval_expression

COMPILE = gcc -Wall -Wextra -Werror -c

LINK = gcc -Wall -Wextra -Werror

SRCS = eval_expression.c eval_expression_utils.c \
		check_expression.c stack.c main.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): eval_expression.h stack.h $(OBJS)
	$(LINK) $(OBJS) -o $(NAME)

%.o: %.c eval_expression.h stack.h
	$(COMPILE) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
