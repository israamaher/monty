#include "monty.h"
/**
 * push_to_stack - Adds a node to the stack.
 * @new: Pointer to the new node.
 * @line_number: Interger representing the line number of of the opcode.
 */
void push(stack_t **new, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (SQ == NULL)
	{
		SQ = *new;
		return;
	}
	tmp = SQ;
	SQ = *new;
	SQ->next = tmp;
	tmp->prev = SQ;
}


/**
 * pall - Adds a node to the stack.
 * @st: Pointer to a pointer pointing to top node of the stack.
 * @ln: line number of  the opcode.
 */
void pall(stack_t **st, unsigned int ln)
{
	stack_t *tmp;

	(void) ln;
	if (st == NULL)
		exit(EXIT_FAILURE);
	tmp = *st;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
