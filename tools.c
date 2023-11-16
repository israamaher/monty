#include "monty.h"

/**
 * openF - opens a file
 * @name: the file namepath
 * Return: void
 */

void openF(char *name)
{
	FILE *fileD = fopen(name, "r");

	if (name == NULL || fileD == NULL)
		error(2, name);

	readF(fileD);
	fclose(fileD);
}


/**
 * readF - reads a file
 * @filed: pointer to file descriptor
 * Return: void
 */

void readF(FILE *filed)
{
	int ln_numb, format = 0;
	char *buf = NULL;
	size_t len = 0;

	for (ln_numb = 1; getline(&buf, &len, filed) != -1; ln_numb++)
	{
		format = parseLn(buf, ln_numb, format);
	}
	free(buf);
}

/**
 * parseLn - Separates each line into tokens to determine
 * which function to call
 * @buf: line from the file
 * @ln_numb: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseLn(char *buf, int ln_numb, int format)
{
	char *opcode, *val;
	const char *del = "\n ";

	if (buf == NULL)
		error(4);

	opcode = strtok(buf, del);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, del);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findFunction(opcode, val, ln_numb, format);
	return (format);
}

/**
 * findFunction - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void findFunction(char *opcode, char *val, int line, int format)
{
	int i;
	int flag;

	instruction_t func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap},
		{"add", addNodes},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	for (flag = 1, i = 0; func[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func[i].opcode) == 0)
		{
			call(func[i].f, opcode, val, line, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, line, opcode);
}

