#include "push_swap.h"

void	write_command(char *str, t_global *g)
{
	if (g->file)
		write(g->fd, str, ft_strlen(str));
	else
	{
		if (g->color && str[0] == 's')
			write(1, "\x1b[33m", 5);
		else if (g->color && str[0] == 'r' && str[1] == 'r' )
			write(1, "\x1b[31m", 5);
		else if (g->color && str [0] == 'r')
			write(1, "\x1b[32m", 5);
		write(1, str, ft_strlen(str));
		write(1, "\x1b[0m", 4);
	}
}

/*
**	swap a - swap the first 2 elements at the top of stack a.
**	Do nothing if there	is only one or no elements).
*/

void	command_sa(t_stacks *s, t_global *g, int display)
{
	t_stack	*tmp;

	if (s->a == NULL || s->a->next == NULL)
		return ;
	tmp = s->a->next;
	s->a->next = s->a->next->next;
	tmp->next = s->a;
	s->a = tmp;
	if (g->visualize)
		display_stacks(s, g);
	else if (display)
		write_command("sa\n", g);
}

/*
**	swap b - swap the first 2 elements at the top of stack b.
**	Do nothing if there	is only one or no elements).
*/

void	command_sb(t_stacks *s, t_global *g, int display)
{
	t_stack	*tmp;

	if (s->b == NULL || s->b->next == NULL)
		return ;
	tmp = s->b->next;
	s->b->next = s->b->next->next;
	tmp->next = s->b;
	s->b = tmp;
	if (g->visualize)
		display_stacks(s, g);
	else if (display)
		write_command("sb\n", g);
}

/*
**	sa and sb at the same time.
*/

void	command_ss(t_stacks *s, t_global *g, int display)
{
	command_sa(s, g, 0);
	command_sb(s, g, 0);
	if (g->visualize)
		display_stacks(s, g);
	else if (display)
		write_command("ss\n", g);
}

/*
**	push a - take the first element at the top of b and put it at the top of a.
**	Do nothing if b is empty.
*/

void	command_pa(t_stacks *s, t_global **g, int display)
{
	t_stack	*tmp;

	if (s->b == NULL)
		return ;
	tmp = s->b;
	s->b = s->b->next;
	tmp->next = s->a;
	s->a = tmp;
	(*g)->size_a += 1;
	(*g)->size_b -= 1;
	if ((*g)->visualize)
		display_stacks(s, *g);
	else if (display)
		write_command("pa\n", *g);
}

/*
**	push b - take the first element at the top of a and put it at the top of b.
**	Do nothing if a is empty.
*/

void	command_pb(t_stacks *s, t_global **g, int display)
{
	t_stack	*tmp;

	if (s->a == NULL)
		return ;
	tmp = s->a;
	s->a = s->a->next;
	tmp->next = s->b;
	s->b = tmp;
	(*g)->size_a -= 1;
	(*g)->size_b += 1;
	if ((*g)->visualize)
		display_stacks(s, *g);
	else if (display)
		write_command("pb\n", *g);
}

/*
**	rotate a - shift up all elements of stack a by 1.
**	The first element becomes the last one.
*/

void	command_ra(t_stacks **s, t_global *g, int display)
{
	t_stack	*new_start;
	t_stack	*new_end;
	t_stack	*tmp;

	if ((*s)->a == NULL || (*s)->a->next == NULL)
		return ;
	tmp = (*s)->a;
	new_start = (*s)->a->next;
	new_end = (*s)->a;
	while (new_end->next)
		new_end = new_end->next;
	tmp->next = NULL;
	new_end->next = tmp;
	(*s)->a = new_start;
	if (g->visualize)
		display_stacks(*s, g);
	else if (display)
		write_command("ra\n", g);
}

/*
**	rotate b - shift up all elements of stack b by 1.
**	The first element becomes the last one.
*/

void	command_rb(t_stacks **s, t_global *g, int display)
{
	t_stack	*new_start;
	t_stack	*new_end;
	t_stack	*tmp;

	if ((*s)->b == NULL || (*s)->b->next == NULL)
		return ;
	tmp = (*s)->b;
	new_start = (*s)->b->next;
	new_end = (*s)->b;
	while (new_end->next)
		new_end = new_end->next;
	tmp->next = NULL;
	new_end->next = tmp;
	(*s)->b = new_start;
	if (g->visualize)
		display_stacks(*s, g);
	else if (display)
		write_command("rb\n", g);
}

/*
**	ra and rb at the same time.
*/

void	command_rr(t_stacks *s, t_global *g, int display)
{
	command_ra(&s, g, 0);
	command_rb(&s, g, 0);
	if (g->visualize)
		display_stacks(s, g);
	else if (display)
		write_command("rr\n", g);
}

/*
**	reverse rotate a - shift down all elements of stack a by 1.
**	The last element becomes the first one.
*/

void	command_rra(t_stacks **s, t_global *g, int display)
{
	t_stack		*new_start;
	t_stack		*new_preend;
	t_stack		*tmp;

	if ((*s)->a == NULL || (*s)->a->next == NULL)
		return ;
	tmp = (*s)->a;
	new_preend = (*s)->a;
	while (new_preend->next->next)
		new_preend = new_preend->next;
	new_start = new_preend->next;
	new_preend->next = NULL;
	new_start->next = tmp;
	(*s)->a = new_start;
	if (g->visualize)
		display_stacks(*s, g);
	else if (display)
		write_command("rra\n", g);
}

/*
**	reverse rotate b - shift down all elements of stack b by 1.
**	The last element becomes the first one.
*/

void	command_rrb(t_stacks **s, t_global *g, int display)
{
	t_stack		*new_start;
	t_stack		*new_preend;
	t_stack		*tmp;

	if ((*s)->b == NULL || (*s)->b->next == NULL)
		return ;
	tmp = (*s)->b;
	new_preend = (*s)->b;
	while (new_preend->next->next)
		new_preend = new_preend->next;
	new_start = new_preend->next;
	new_preend->next = NULL;
	new_start->next = tmp;
	(*s)->b = new_start;
	if (g->visualize)
		display_stacks(*s, g);
	else if (display)
		write_command("rrb\n", g);
}

/*
**	rra and rrb at the same time.
*/

void	command_rrr(t_stacks *s, t_global *g, int display)
{
	command_rra(&s, g, 0);
	command_rrb(&s, g, 0);
	if (g->visualize)
		display_stacks(s, g);
	else if (display)
		write_command("rrr\n", g);
}
