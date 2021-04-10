/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "stack.h"

int		*init_stack(t_stack *stack, int size)
{
	stack->data = malloc(size * sizeof(int));
	stack->status = 0;
	stack->size = size;
	return (stack->data); // if malloc fails the function returns null
}

int		is_empty(t_stack *stack)
{
	return (stack->status == 0);
}

int		is_full(t_stack *stack)
{
	return (stack->status == stack->size);
}

void	push(t_stack *stack, int element)
{
	stack->data[stack->status] = element;
	stack->status++;
}

int		pop(t_stack *stack)
{
	int	popped;

	popped = stack->data[stack->status- 1];
	stack->status--;
	return (popped);
}
