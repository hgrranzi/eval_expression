/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef EVAL_EXPRESSION_H
# define EVAL_EXPRESSION_H

# include <unistd.h>
# include "stack.h"

# include <stdio.h>

# define STACK_SIZE 64

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
int		is_priority(int a, int b); // check if a is priority b
int		priority(int a); // init the priority of a
int		is_bracket(int a); // check if a is a bracket

char	*remove_spaces(char *argv);
void	check_wrong(char *str);
void	display_error(void);

void	aka_putchar(char c);
void	aka_putnbr(int nbr);
int		aka_isdigit(char c);
int		aka_strlen(char *str);
int		aka_strchr(char *str, char c);
int		aka_atoi(char *str);

void	print_stack(t_stack *stack);

#endif
