/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

#define ADD_STACK 64

typedef struct	s_stack
{
	int			*data; // the element
	int			status; // number of elements in the stack
	int			size; // the size of the stack
}				t_stack;

int				*init_stack(t_stack *stack, int size);

#endif
