#include "push_swap.h"

void	write_command(char *str, int color)
{
	if (color && str[0] == 's')
		write(1, "\x1b[33m", 5);
	else if (color && str[0] == 'r' && str[1] == 'r' )
		write(1, "\x1b[31m", 5);
	else if (color && str [0] == 'r')
		write(1, "\x1b[32m", 5);
	write(1, str, ft_strlen(str));
	write(1, "\n\x1b[0m", 5);
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

void	command_sa(t_stack *a, int display, int color)
{
	int		buff;

	if (a == NULL || a->next == NULL)
		return ;
	buff = a->data;
	a->data = a->next->data;
	a->next->data = buff;
	if (display)
		write_command("sa", color);
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

void	command_sb(t_stack *b, int display, int color)
{
	int		buff;

	if (b == NULL || b->next == NULL)
		return ;
	buff = b->data;
	b->data = b->next->data;
	b->next->data = buff;
	if (display)
		write_command("sb", color);
}

/*
**		ss: sa и sb одновременно.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_ss(t_stacks *s, int display, int color)
{
	command_sa(s->a, 0, color);
	command_sb(s->b, 0, color);
	if (display)
		write_command("ss", color);
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

void	command_pa(t_stacks *s, t_global **g, int display, int color)
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
	if (display)
		write_command("pa", color);
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

void	command_pb(t_stacks *s, t_global **g, int display, int color)
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
	if (display)
		write_command("pb", color);
}

/*
**		ra: rotate a -  сдвинуть вверх все элементы стека  a  на 1.
**		Верхний элемент отправляется вниз.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_ra(t_stack **a, int display, int color)
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
	if (display)
		write_command("ra", color);
}

/*
**		rb: rotate b -  сдвинуть вверх все элементы стека  b  на 1.
**		Верхний элемент отправляется вниз.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rb(t_stack **b, int display, int color)
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
	if (display)
		write_command("rb", color);
}

/*
**		rr: ra и rb одновременно.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rr(t_stacks *s, int display, int color)
{
	command_ra(&s->a, 0, color);
	command_rb(&s->b, 0, color);
	if (display)
		write_command("rr", color);
}

/*
**		rra: reverse rotate a -  сдвинуть вниз все элементы стека  a на 1.
**		Нижний элемент отправляется наверх.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rra(t_stack **a, int display, int color)
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
	// printf("display = %i, color = %i\n", display, color);
	if (display)
		write_command("rra", color);
}

/*
**		rrb: reverse rotate b -  сдвинуть вниз все элементы стека  b на 1.
**		Нижний элемент отправляется наверх.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rrb(t_stack **b, int display, int color)
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
	if (display)
		write_command("rrb", color);
}

/*
**		rrr: rrа и rrb одновременно.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	command_rrr(t_stacks *s, int display, int color)
{
	command_rra(&s->a, 0, color);
	command_rrb(&s->b, 0, color);
	if (display)
		write_command("rrr", color);
}