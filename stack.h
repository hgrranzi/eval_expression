/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct	s_stack
{
	int			*data; // the element
	int			status; // number of elements in the stack
	int			size; // the size of the stack
}				t_stack;

int				*init_stack(t_stack *stack, int size);
int				is_empty(t_stack *stack);
int				is_full(t_stack *stack);
void			push(t_stack *stack, int element);
int				pop(t_stack *stack);
void			destroy_stack(t_stack *stack);

#endif
