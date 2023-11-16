#include "monty.h"


/**
 * push1 - ...
 * @new:...
 * @line:....
 */
void push1(stack_t **new, __attribute__((unused))unsigned int line)
{
stack_t *t;
if (new == NULL || *new == NULL)
{
exit(EXIT_FAILURE);
}
if (head == NULL)
{
head = *new;
return;
}
t = head;
head = *new;
head->next = t;
t->prev = head;
}


/**
 * pall1 -  ....
 * @st:....
 * @line:.....
 */
void pall1(stack_t **st, unsigned int line)
{
stack_t *t;
(void) line;
if (st == NULL)
{
exit(EXIT_FAILURE);
}
t = *st;
while (t != NULL)
{
printf("%d\n", t->n);
t = t->next;
}
}

/**
 * pop1 -.....
 * @st: ...
 * @line:.....
 */
void pop1(stack_t **st, unsigned int line)
{
stack_t *t;
if (st == NULL || *st  == NULL)
{
prr2(7, line);
}
t = *st;
*st = t->next;
if (*st != NULL)
{
(*st)->prev = NULL;
}
free(t);
}

/**
 * pint1-.....
 * @st:......
 * @line:.....
 */
void pint1(stack_t **st, unsigned int line)
{
if (st == NULL || *st == NULL)
{
prr2(6, line);
}
printf("%d\n", (*st)->n);
}

