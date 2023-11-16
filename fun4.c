#include "main.h"

/**
 * p_ch -....
 * @s:....
 * @line:....
 */
void p_ch(stack_t **s, unsigned int line)
{
int iv;
if (s == NULL || *s == NULL)
{
prr3(11, line);
}
iv = (*s)->n;
if (iv < 0 || iv > 127)
{
prr3(10, line);
}
printf("%c\n", iv);
}

/**
 * p_str - ....
 * @s:...
 * @line:...
 */
void p_str(stack_t **s, __attribute__((unused))unsigned int line)
{
int iv;
stack_t *t;
if (s == NULL || *s == NULL)
{
printf("\n");
return;
}
t = *s;
while (t != NULL)
{
iv = t->n;
if (iv <= 0 || iv > 127)
{
break;
}
printf("%c", iv);
t = t->next;
}
printf("\n");
}

/**
 * rotl1 -...
 * @s: ...
 * @line: ....
 */
void rotl1(stack_t **s, __attribute__((unused))unsigned int line)
{
stack_t *t;
if (s == NULL || *s == NULL || (*s)->next == NULL)
{
return;
}
t = *s;
while (t->next != NULL)
{
t = t->next;
}
t->next = *s;
(*s)->prev = t;
*s = (*s)->next;
(*s)->prev->next = NULL;
(*s)->prev = NULL;
}


/**
 * rotr1 -....
 * @s: ............
 * @line:....
 */
void rotr1(stack_t **s, __attribute__((unused))unsigned int line)
{
stack_t *t;
if (s == NULL || *s == NULL || (*s)->next == NULL)
{
return;
}
t = *s;
while (t->next != NULL)
{
t = t->next;
}
t->next = *s;
t->prev->next = NULL;
t->prev = NULL;
(*s)->prev = t;
(*s) = t;
}

