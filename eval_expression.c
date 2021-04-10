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
	while (i < stack->status)
	{
		aka_putnbr(stack->data[i]);
		aka_putchar(' ');
		i++;
	}
	aka_putchar('\n');
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

int			check_priority(char c)
{
	if (c == '+' || c == '-')
		return (0);
	return (1);
}

void		take_operator()
{
	// here we put an operator or a bracket to the operators stak or we eval an expression
	return ;
}

void		take_operand()
{
	//here we convert chars to integer and put it to the operands stack
	return ;
}

int			eval_expression(char *argv)
{
	int		res;
	char	*str;
	int		i;

	res = 0;
	i = 0;
	if (!(str = remove_spaces(argv)))
		display_error();
	check_wrong(str);
	while (str[i])
	{
		take_operand();
		take_operator();
		i++;
	}

	return (res);
}
