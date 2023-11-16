#include "monty.h"

/**
 * nop - Does nothing.
 * @st: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void nop(stack_t **st, unsigned int ln)
{
	(void)st;
	(void)ln;
}


/**
 * swap - Swaps the top two elements of the stack.
 * @st: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void swap(stack_t **st, unsigned int ln)
{
	stack_t *tmp;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		moreErr(8, ln, "swap");
	tmp = (*st)->next;
	(*st)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *st;
	tmp->next = *st;
	(*st)->prev = tmp;
	tmp->prev = NULL;
	*st = tmp;
}

/**
 * addNodes - Adds the top two elements of the stack.
 * @st: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void addNodes(stack_t **st, unsigned int ln)
{
	int sum;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		moreErr(8, ln, "add");

	(*st) = (*st)->next;
	sum = (*st)->n + (*st)->prev->n;
	(*st)->n = sum;
	free((*st)->prev);
	(*st)->prev = NULL;
}
