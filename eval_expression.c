/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "eval_expression.h"

char	*remove_spaces(char *argv)
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
	str = malloc((aka_strlen(argv) - spaces + 1) * sizeof(char));
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

int		eval_expression(char *argv)
{
	int		res;
	char	*str;

	res = 0;
	str = remove_spaces(argv);
	return (res);
}
