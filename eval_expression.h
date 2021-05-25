/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef EVAL_EXPRESSION_H
# define EVAL_EXPRESSION_H

# include <unistd.h>
# include "stack.h"

# define STACK_SIZE 64
# define MAX_INT 2147483647

# define PLUS 43
# define MINUS 45
# define MULTI 42
# define DIVISE 47
# define MODULO 37
# define OPEN_B 40
# define CLOSE_B 41


int		eval_expression(char *str);

void	eval_before(t_stack *operator, t_stack *number); // eval two closest numbers in stack
int		take_operator(t_stack *operator, t_stack *number, int symb, int i); // put an operator to the stack or call eval_before and move the str index
int		take_number(t_stack *number, char *str, int i); //convert chars to integer, put it to the number stack and move the str index

int		is_priority(int a, int b);
int		priority(int a);
int		is_bracket(int a);
char	*remove_spaces(char *argv);
void	check_expression(char *str);
void	display_error(void);

void	aka_putchar(char c);
void	aka_putnbr(long int nbr);
int		aka_isdigit(char c);
int		aka_strlen(char *str);
int		aka_strchr(char *str, char c);
int		aka_atoi(char *str);

void	print_stack(t_stack *stack);

#endif
