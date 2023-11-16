#include "main.h"

/**
 * o_file - ....
 * @_file:.....
 * Return: ....
 */

void o_file(char *_file)
{
FILE *fd = fopen(_file, "r");
if (_file == NULL || fd == NULL)
{
prr(2, _file);
}
r_file(fd);
fclose(fd);
}


/**
 * r_file -.....
 * @fd:...
 * Return:....
 */

void r_file(FILE *fd)
{
int line, forma = 0;
char *buf = NULL;
size_t len = 0;
for (line = 1; getline(&buf, &len, fd) != -1; line++)
{
forma = p_l(buf, line, forma);
}
free(buf);
}


/**
 * p_l - ....
 * @buf:.....
 * @line: ....
 * @forma:....
 * Return: ...
 */

int p_l(char *buf, int line, int forma)
{
char *opcode, *v;
const char *del = "\n ";
if (buf == NULL)
{
prr(4);
}

opcode = strtok(buf, del);
if (opcode == NULL)
{
return (forma);
}
v = strtok(NULL, del);
if (strcmp(opcode, "stack") == 0)
{
return (0);
}
if (strcmp(opcode, "queue") == 0)
{
return (1);
}

sel(opcode, v, line, forma);
return (forma);
}

/**
 * sel-.....
 * @opcode: ...
 * @v:....
 * @forma:....
 * @line:.....
 * Return:....
 */
void sel(char *opcode, char *v, int line, int forma)
{
int i;
int f;

instruction_t func_list[] = {
		{"push", push1},
		{"pall", pall1},
		{"pint", pint1},
		{"pop", pop1},
		{"nop", nop1},
		{"swap", swap1},
		{"add", add1},
		{"sub", sub1},
		{"div", div1},
		{"mul", mul1},
		{"mod", mod1},
		{"pchar", p_ch},
		{"pstr", p_str},
		{"rotl", rotl1},
		{"rotr", rotr1},
		{NULL, NULL}
};

if (opcode[0] == '#')
{
return;
}

for (f = 1, i = 0; func_list[i].opcode != NULL; i++)
{
if (strcmp(opcode, func_list[i].opcode) == 0)
{
exe(func_list[i].f, opcode, v, line, forma);
f = 0;
}
}
if (f == 1)
{
prr(3, line, opcode);
}
}


/**
 * exe - .....
 * @func: ....
 * @op:...
 * @v:....
 * @line:....
 * @forma:.....
 */
void exe(op_func func, char *op, char *v, int line, int forma)
{
stack_t *new;
int f;
int i;
f = 1;
if (strcmp(op, "push") == 0)
{
if (v != NULL && v[0] == '-')
{
v = v + 1;
f = -1;
}
if (v == NULL)
{
prr(5, line);
}
for (i = 0; v[i] != '\0'; i++)
{
if (isdigit(v[i]) == 0)
{
prr(5, line);
}
}
new = c_node(atoi(v) * f);
if (forma == 0)
{
func(&new, line);
}
if (forma == 1)
{
_queue(&new, line);
}
}
else
{
func(&head, line);
}
}

