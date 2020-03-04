#include "push_swap.h"

/*
**		sa: swap a - поменяйте местами первые 2 элемента в
**		верхней части стека a. Ничего не делать, если есть
**		только один или нет элементов.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_sa(t_stack *a, int i)
{
	int		buff;

	if (a == NULL || a->next == NULL)
		return ;
	buff = a->data;
	a->data = a->next->data;
	a->next->data = buff;
	if (i == 1)
		write(1, "sa\n", 3);
}

/*
**		sb: swap b - поменять первые 2 элемента в
**		верхней части стека b. Ничего не делать, если есть
**		только один или нет элементов.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_sb(t_stack *b, int i)
{
	int		buff;

	if (b == NULL || b->next == NULL)
		return ;
	buff = b->data;
	b->data = b->next->data;
	b->next->data = buff;
	if (i == 1)
		write(1, "sb\n", 3);
}

/*
**		ss: sa и sb одновременно.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_ss(t_stacks *s, int i)
{
	command_sa(s->a, 0);
	command_sb(s->b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

/*
**		pa: push a - возьмите первый элемент вверху
**		b и поместите его вверху  a. Ничего не делать,
**		если b пусто.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_pa(t_stacks *s, t_global *g, int i)
{
	t_stack	*buff;

	if (s->b == NULL)
		return ;
	g->size_a += 1;
	g->size_b -= 1;
	buff = s->b;
	s->b = s->b->next;
	buff->next = s->a;
	s->a = buff;
	if (i == 1)
		write(1, "pa\n", 3);
}

/*
**		pb: push b - возьмите первый элемент в верхней части
**		a и поместите его в верхней части  b.
**		Ничего не делать, если  a пусто.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_pb(t_stacks *s, t_global *g, int i)
{
	t_stack	*buff;

	if (s->a == NULL)
		return ;
	g->size_a -= 1;
	g->size_b += 1;
	buff = s->a;
	s->a = s->a->next;
	buff->next = s->b;
	s->b = buff;
	if (i == 1)
		write(1, "pb\n", 3);
}
