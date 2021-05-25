/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "eval_expression.h"

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

void		display_error(void)
{
	write(2, "Error\n", 6);
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

void		check_expression(char *str)
{
	int		i;
	int		open_bracket;
	int		close_bracket;
	char	operators[] = "+-*/%%";

	i = 0;
	open_bracket = close_bracket = 0;
	while (str[i] && (aka_isdigit(str[i]) || aka_strchr(operators, str[i])
		|| is_bracket(str[i])))
	{
		if (str[i] == OPEN_B)
		{
			if (i != 0 && aka_isdigit(str[i - 1]))
				display_error();
			open_bracket++;
		}
		if (str[i] == CLOSE_B)
		{
			if (aka_isdigit(str[i + 1]))
				display_error();
			close_bracket++;
		}
		i++;
	}
	if (open_bracket != close_bracket || str[i] != '\0')
		display_error();
}
