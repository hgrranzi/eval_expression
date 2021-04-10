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
	while (!is_empty(operator) && !is_bracket(symb)
	&& !is_priority(symb, operator->data[operator->status - 1]))
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
	check_expression(str);
	if (!(init_stack(&number, STACK_SIZE))
	|| (!init_stack(&operator, STACK_SIZE)))
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
