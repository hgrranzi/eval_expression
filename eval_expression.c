/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "eval_expression.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	write(1, "----------\n", 11);
	while (i < stack->status)
	{
		aka_putnbr(stack->data[i]);
		aka_putchar(' ');
		i++;
	}
	aka_putchar('\n');
	write(1, "----------\n", 11);
}

void		display_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

char		*remove_spaces(char *argv)
{
	char	*str;
	int		i;
	int		j;
	int		spaces;

	i = 0;
	j = 0;
	spaces = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			spaces++;
		i++;
	}
	if (!(str = malloc((aka_strlen(argv) - spaces + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
			str[j++] = argv[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

void		check_wrong(char *str)
{
	int		i;
	int		open_bracket;
	int		close_bracket;
	char	operators[] = "+-*/%%";
	char	chs[] = "()";

	i = 0;
	open_bracket = close_bracket = 0;
	while (str[i] && (aka_isdigit(str[i]) || aka_strchr(operators, str[i])
		|| aka_strchr(chs, str[i])))
	{
		if (str[i] == '(')
			open_bracket++;
		if (str[i] == ')')
			close_bracket++;
		i++;
	}
	if (open_bracket != close_bracket || str[i] != '\0')
		display_error();
}

int			is_bracket(int a)
{
	return (a == OPEN_B || a == CLOSE_B);
}

int			priority(int a)
{
	if (a == PLUS || a == MINUS)
		return (1);
	if (a == MULTI || a == DIVISE || a == MODULO)
		return (2);
	return (0);
}

int			is_priority(int a, int b)
{
	return (priority(a) > priority(b));
}

void		eval_before(t_stack *operator, t_stack *number)
{
	int		a;
	int		b;

	b = pop(number);
	a = pop(number);
	switch (pop(operator))
	{
	case PLUS:
		push(number, a + b);
		break;
	case MINUS:
		push(number, a - b);
		break;
	case MULTI:
		push(number, a * b);
		break;
	case DIVISE:
		push(number, a / b);
		break;
	case MODULO:
		push(number, a % b);
		break;
	default:
		break;
	}
}

int			take_operator(t_stack *operator, t_stack *number, int symb, int i)
{
	while (!is_empty(operator) && !is_bracket(symb) && !is_priority(symb, operator->data[operator->status - 1]))
		eval_before(operator, number);
	if (symb == CLOSE_B)
	{
		while (operator->data[operator->status - 1] != OPEN_B)
			eval_before(operator, number);
		pop(operator);
	}
	else
		push(operator, symb);
	return (i + 1);
}

int			take_number(t_stack *number, char *str, int i)
{
	int		num;
	num = aka_atoi(&str[i]);
	push(number, num);
	while (aka_isdigit(str[i]))
		i++;
	return (i);
}

int			eval_expression(char *argv)
{
	int		res;
	char	*str;
	int		i;
	t_stack	number;
	t_stack	operator;

	i = 0;
	if (!(str = remove_spaces(argv)))
		display_error();
	check_wrong(str);
	if (!(init_stack(&number, STACK_SIZE)) || (!init_stack(&operator, STACK_SIZE)))
		display_error();
	while (str[i])
	{
		if (aka_isdigit(str[i]))
			i = take_number(&number, str, i);
		else
			i = take_operator(&operator, &number, str[i], i);
	}
	while (operator.status)
		eval_before(&operator, &number);
	res = number.data[0];
	destroy_stack(&number);
	destroy_stack(&operator);
	free(str);
	return (res);
}
