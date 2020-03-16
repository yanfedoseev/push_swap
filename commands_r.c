#include "push_swap.h"

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
