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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


void o_file(char *_file);
int p_l(char *buf, int line, int forma);
void r_file(FILE *);
void sel(char *, char *, int, int);
stack_t *c_node(int n);
void frees(void);
void pall1(stack_t **, unsigned int);
void push1(stack_t **, unsigned int);
void _queue(stack_t **, unsigned int);

void exe(op_func, char *, char *, int, int);

void pint1(stack_t **, unsigned int);
void pop1(stack_t **, unsigned int);
void nop1(stack_t **, unsigned int);
void swap1(stack_t **, unsigned int);


void add1(stack_t **, unsigned int);
void sub1(stack_t **, unsigned int);
void div1(stack_t **, unsigned int);
void mul1(stack_t **, unsigned int);
void mod1(stack_t **, unsigned int);

void prr(int o, ...);
void prr2(int o, ...);
void prr3(int o, ...);
void rotr1(stack_t **, unsigned int);

void p_ch(stack_t **, unsigned int);
void p_str(stack_t **, unsigned int);
void rotl1(stack_t **, unsigned int);




#endif

