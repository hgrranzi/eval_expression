/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "stack.h"

int	*init_stack(t_stack *stack, int size)
{
	stack->data = malloc(size * sizeof(int));
	stack->status = 0;
	stack->size = size;
	return (stack->data);
}
