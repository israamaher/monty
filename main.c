#include "main.h"
stack_t *SQ = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openF(argv[1]);
	freeN();
	return (0);
}

/**
 * createN - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *createN(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * freeN - Frees nodes in the stack.
 */
void freeN(void)
{
	stack_t *tmp;

	if (SQ == NULL)
		return;

	while (SQ != NULL)
	{
		tmp = SQ;
		SQ = SQ->next;
		free(tmp);
	}
}


/**
 * addQueue - Adds a node to the queue.
 * @new: Pointer to the new node.
 * @line: line number of the opcode.
 */
void addQueue(stack_t **new, __attribute__((unused))unsigned int line)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new;
	(*new)->prev = tmp;
}
