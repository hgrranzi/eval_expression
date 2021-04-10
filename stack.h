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
	void		*data; // the element
	unsigned	status; // number of elements in the stack
	unsigned	size; // the size of the stack
}				t_stack;

#endif
