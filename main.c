/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "eval_expression.h"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		aka_putnbr(eval_expression(argv[1]));
		write(1, "\n", 1);
	}
	return (0);
}
