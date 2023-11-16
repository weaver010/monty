#include "main.h"

/**
 * mul1 - .....
 * @st:...
 * @n: ..
 */
void mul1(stack_t **st, unsigned int n)
{
int s;
if (st == NULL || *st == NULL || (*st)->next == NULL)
{
prr2(8, n, "mul");
}
(*st) = (*st)->next;
s = (*st)->n * (*st)->prev->n;
(*st)->n = s;
free((*st)->prev);
(*st)->prev = NULL;
}


/**
 * mod1 - .........
 * @st:....
 * @n: .....
 */
void mod1(stack_t **st, unsigned int n)
{
int s;
if (st == NULL || *st == NULL || (*st)->next == NULL)
{
prr2(8, n, "mod");
}
if ((*st)->n == 0)
{
prr2(9, n);
}
(*st) = (*st)->next;
s = (*st)->n % (*st)->prev->n;
(*st)->n = s;
free((*st)->prev);
(*st)->prev = NULL;
}

