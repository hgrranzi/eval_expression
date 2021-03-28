/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "eval_expression.h"

int main(int argc, char **argv)
{
	if (argc == 2)
		aka_putnbr(eval_expression(argv[1]));
	else
		write(1, "Error", 5);
	write(1, "\n", 1);
	return (0);
}
