#include "push_swap.h"

void	write_command(char *str, t_global *g)
{
	if (g->color && str[0] == 's')
		write(1, "\x1b[33m", 5);
	else if (g->color && str[0] == 'r' && str[1] == 'r' )
		write(1, "\x1b[31m", 5);
	else if (g->color && str [0] == 'r')
		write(1, "\x1b[32m", 5);
	ft_printf("%s\x1b[0m\n", str);
}

/*
**		sa: swap a - поменяйте местами первые 2 элемента в
**		верхней части стека a. Ничего не делать, если есть
**		только один или нет элементов.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_sa(t_stacks *s, t_global *g, int display)
{
	int		buff;

	if (s->a == NULL || s->a->next == NULL)
		return ;
	buff = s->a->data;
	s->a->data = s->a->next->data;
	s->a->next->data = buff;
	if (g->visualize)
		display_stacks(s, g);
	else if (display)
		write_command("sa", g);
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

void	command_sb(t_stacks *s, t_global *g, int display)
{
	int		buff;

	if (s->b == NULL || s->b->next == NULL)
		return ;
	buff = s->b->data;
	s->b->data = s->b->next->data;
	s->b->next->data = buff;
	if (g->visualize)
		display_stacks(s, g);
	else if (display)
		write_command("sb", g);
}

/*
**		ss: sa и sb одновременно.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_ss(t_stacks *s, t_global *g, int display)
{
	command_sa(s, g, 0);
	command_sb(s, g, 0);
	if (g->visualize)
		display_stacks(s, g);
	else if (display)
		write_command("ss", g);
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

void	command_pa(t_stacks *s, t_global **g, int display)
{
	t_stack	*buff;

	if (s->b == NULL)
		return ;
	(*g)->size_a += 1;
	(*g)->size_b -= 1;
	buff = s->b;
	s->b = s->b->next;
	buff->next = s->a;
	s->a = buff;
	if ((*g)->visualize)
		display_stacks(s, *g);
	else if (display)
		write_command("pa", *g);
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

void	command_pb(t_stacks *s, t_global **g, int display)
{
	t_stack	*buff;

	if (s->a == NULL)
		return ;
	(*g)->size_a -= 1;
	(*g)->size_b += 1;
	buff = s->a;
	s->a = s->a->next;
	buff->next = s->b;
	s->b = buff;
	if ((*g)->visualize)
		display_stacks(s, *g);
	else if (display)
		write_command("pb", *g);
}

/*
**		ra: rotate a -  сдвинуть вверх все элементы стека  a  на 1.
**		Верхний элемент отправляется вниз.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_ra(t_stacks **s, t_global *g, int display)
{
	t_stack	*first_list;
	t_stack	*rotate_list;
	t_stack	*last_list;

	if ((*s)->a == NULL || (*s)->a->next == NULL)
		return ;
	rotate_list = (*s)->a;
	first_list = (*s)->a->next;
	last_list = (*s)->a;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	(*s)->a = first_list;
	if (g->visualize)
		display_stacks(*s, g);
	else if (display)
		write_command("ra", g);
}

/*
**		rb: rotate b -  сдвинуть вверх все элементы стека  b  на 1.
**		Верхний элемент отправляется вниз.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rb(t_stacks **s, t_global *g, int display)
{
	t_stack	*first_list;
	t_stack	*rotate_list;
	t_stack	*last_list;

	if ((*s)->b == NULL || (*s)->b->next == NULL)
		return ;
	rotate_list = (*s)->b;
	first_list = (*s)->b->next;
	last_list = (*s)->b;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	(*s)->b = first_list;
	if (g->visualize)
		display_stacks(*s, g);
	else if (display)
		write_command("rb", g);
}

/*
**		rr: ra и rb одновременно.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rr(t_stacks *s, t_global *g, int display)
{
	command_ra(&s, g, 0);
	command_rb(&s, g, 0);
	if (g->visualize)
		display_stacks(s, g);
	else if (display)
		write_command("rr", g);
}

/*
**		rra: reverse rotate a -  сдвинуть вниз все элементы стека  a на 1.
**		Нижний элемент отправляется наверх.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rra(t_stacks **s, t_global *g, int display)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*penultimate_list;

	if ((*s)->a == NULL || (*s)->a->next == NULL)
		return ;
	first_list = (*s)->a;
	penultimate_list = (*s)->a;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	(*s)->a = rotate_list;
	if (g->visualize)
		display_stacks(*s, g);
	else if (display)
		write_command("rra", g);
}

/*
**		rrb: reverse rotate b -  сдвинуть вниз все элементы стека  b на 1.
**		Нижний элемент отправляется наверх.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rrb(t_stacks **s, t_global *g, int display)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*penultimate_list;

	if ((*s)->b == NULL || (*s)->b->next == NULL)
		return ;
	first_list = (*s)->b;
	penultimate_list = (*s)->b;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	(*s)->b = rotate_list;
	if (g->visualize)
		display_stacks(*s, g);
	else if (display)
		write_command("rrb", g);
}

/*
**		rrr: rrа и rrb одновременно.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rrr(t_stacks *s, t_global *g, int display)
{
	command_rra(&s, g, 0);
	command_rrb(&s, g, 0);
	if (g->visualize)
		display_stacks(s, g);
	else if (display)
		write_command("rrr", g);
}