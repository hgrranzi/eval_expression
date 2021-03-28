/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef EVAL_EXPRESSION_H
# define EVAL_EXPRESSION_H

# include <unistd.h>
# include <stdlib.h>

int		eval_expression(char *str);

char	*remove_spaces(char *argv);

void	aka_putchar(char c);
void	aka_putnbr(int nbr);
int		aka_strlen(char *str);

#endif
