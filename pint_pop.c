#include "monty.h"
/**
 * pop_top - Adds a node to the stack.
 * @st: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **st, unsigned int ln)
{
	stack_t *tmp;

	if (st == NULL || *st == NULL)
		moreErr(7, ln);

	tmp = *st;
	*st = tmp->next;
	if (*st != NULL)
		(*st)->prev = NULL;
	free(tmp);
}

/**
 * pint - Prints the top node of the stack.
 * @st: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void pint(stack_t **st, unsigned int ln)
{
	if (st == NULL || *st == NULL)
		moreErr(6, ln);
	printf("%d\n", (*st)->n);
}
