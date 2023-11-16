#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *SQ;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void openF(char *name);
int parseLn(char *buf, int ln_numb, int format);
void readF(FILE *filed);
void findFunction(char *opcode, char *val, int line, int format);
void call(op_func function, char *op_code, char *value, int line, int format);

/*Stack operations*/
stack_t *createN(int n);
void freeN(void);
void addQueue(stack_t **, unsigned int);

void pall(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);

/*Error hanlding*/
void error(int err, ...);
void moreErr(int err, ...);
#endif
