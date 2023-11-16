#include "main.h"
stack_t *head = NULL;

/**
 * main - ....
 * @ac: ....
 * @av: ....
 * Return:...
 */

int main(int ac, char *av[])
{
if (ac != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
o_file(av[1]);
frees();
return (0);
}

/**
 * c_node - ...
 * @n: ...
 * Return: ...
 */
stack_t *c_node(int n)
{
stack_t *new_n;

new_n = malloc(sizeof(stack_t));
if (new_n == NULL)
{
prr(4);
}
new_n->next = NULL;
new_n->prev = NULL;
new_n->n = n;
return (new_n);
}

/**
 * frees-....
 */
void frees(void)
{
stack_t *t;
if (head == NULL)
{
return;
}
while (head != NULL)
{
t = head;
head = head->next;
free(t);
}
}


/**
 * _queue - ....
 * @new: ....
 * @ln:...
 */
void _queue(stack_t **new, __attribute__((unused))unsigned int ln)
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
while (t->next != NULL)
{
t = t->next;
}
t->next = *new;
(*new)->prev = t;
}

