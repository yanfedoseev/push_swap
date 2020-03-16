#include "push_swap.h"

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
