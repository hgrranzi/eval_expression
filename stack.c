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

void	resize_stack(t_stack *stack)
{
	int	*tmp_data;
	int	i;

	stack->size += STACK_SIZE;
	tmp_data = malloc((stack->size) * sizeof(int));
	if (!tmp_data)
		display_error();
	i = 0;
	while (i < stack->status)
	{
		tmp_data[i] = stack->data[i];
		i++;
	}
	free(stack->data);
	stack->data = tmp_data;
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
	if (is_full(stack))
		resize_stack(stack);
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

void	destroy_stack(t_stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	stack->status = 0;
	stack->size = 0;
}
