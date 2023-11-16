#include "monty.h"

/**
 * nop1 - .....
 * @s: ...........
 * @n:....
 */
void nop1(stack_t **s, unsigned int n)
{
(void)s;
(void)n;
}


/**
 * swap1 - .....
 * @s: .....
 * @n:......
 */
void swap1(stack_t **s, unsigned int n)
{
stack_t *t;
if (s == NULL || *s == NULL || (*s)->next == NULL)
{
prr2(8, n, "swap");
}
t = (*s)->next;
(*s)->next = t->next;
if (t->next != NULL)
{
t->next->prev = *s;
}
t->next = *s;
(*s)->prev = t;
t->prev = NULL;
*s = t;
}

/**
 * add1 -.....
 * @st: .....
 * @n:.....
 */
void add1(stack_t **st, unsigned int n)
{
int s;
if (st == NULL || *st == NULL || (*st)->next == NULL)
{
prr2(8, n, "add");
}
(*st) = (*st)->next;
s = (*st)->n + (*st)->prev->n;
(*st)->n = s;
free((*st)->prev);
(*st)->prev = NULL;
}


/**
 * sub1 - ....
 * @st: .....
 * @n: ....
 */
void sub1(stack_t **st, unsigned int n)
{
int s;
if (st == NULL || *st == NULL || (*st)->next == NULL)
{
prr2(8, n, "sub");
}
(*st) = (*st)->next;
s = (*st)->n - (*st)->prev->n;
(*st)->n = s;
free((*st)->prev);
(*st)->prev = NULL;
}


/**
 * div1 - .....
 * @st: .....
 * @n:......
 */
void div1(stack_t **st, unsigned int n)
{
int s;
if (st == NULL || *st == NULL || (*st)->next == NULL)
{
prr2(8, n, "div");
}
if ((*st)->n == 0)
{
prr2(9, n);
}
(*st) = (*st)->next;
s = (*st)->n / (*st)->prev->n;
(*st)->n = s;
free((*st)->prev);
(*st)->prev = NULL;
}

