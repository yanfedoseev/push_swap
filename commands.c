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

/*
**		ra: rotate a -  сдвинуть вверх все элементы стека  a  на 1.
**		Верхний элемент отправляется вниз.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_ra(t_stack **a, int i)
{
	t_stack	*first_list;
	t_stack	*rotate_list;
	t_stack	*last_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	rotate_list = *a;
	first_list = (*a)->next;
	last_list = *a;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*a = first_list;
	if (i == 1)
		write(1, "ra\n", 3);
}

/*
**		rb: rotate b -  сдвинуть вверх все элементы стека  b  на 1.
**		Верхний элемент отправляется вниз.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rb(t_stack **b, int i)
{
	t_stack	*first_list;
	t_stack	*rotate_list;
	t_stack	*last_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	rotate_list = *b;
	first_list = (*b)->next;
	last_list = *b;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*b = first_list;
	if (i == 1)
		write(1, "rb\n", 3);
}

/*
**		rr: ra и rb одновременно.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rr(t_stacks *s, int i)
{
	if (i == 1)
		write(1, "rr\n", 3);
	command_ra(&s->a, 0);
	command_rb(&s->b, 0);
}

/*
**		rra: reverse rotate a -  сдвинуть вниз все элементы стека  a на 1.
**		Нижний элемент отправляется наверх.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rra(t_stack **a, int i)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*penultimate_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	first_list = *a;
	penultimate_list = *a;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*a = rotate_list;
	if (i == 1)
		write(1, "rra\n", 4);
}

/*
**		rrb: reverse rotate b -  сдвинуть вниз все элементы стека  b на 1.
**		Нижний элемент отправляется наверх.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rrb(t_stack **b, int i)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*penultimate_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	first_list = *b;
	penultimate_list = *b;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*b = rotate_list;
	if (i == 1)
		write(1, "rrb\n", 4);
}

/*
**		rrr: rrа и rrb одновременно.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rrr(t_stacks *s, int i)
{
	command_rra(&s->a, 0);
	command_rrb(&s->b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}