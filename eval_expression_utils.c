/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "eval_expression.h"

void	aka_putchar(char c)
{
	write(1, &c, 1);
}

void	aka_putnbr(int nbr)
{
	if (nbr < 0)
	{
		aka_putchar('-');
		aka_putnbr(-nbr);
	}
	if (nbr > 9)
	{
		aka_putnbr(nbr / 10);
		aka_putnbr(nbr % 10);
	}
	else
		aka_putchar(nbr + 48);
}

int		aka_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int		aka_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		aka_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		aka_atoi(char *str)
{
	int	nbr;

	nbr = 0;
	return (nbr);
}
