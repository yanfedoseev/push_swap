#include "push_swap.h"

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
