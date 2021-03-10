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
