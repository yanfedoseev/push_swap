#include "push_swap.h"

void	set_number_of_steps_to_top(t_stack *s, int stack_size)
{
	int		i;
	t_stack	*tmp;

	tmp = s;
	i = -1;
	while (++i <= stack_size / 2)
	{
		tmp->steps = i;
		tmp->rotate = 1;
		tmp = tmp->next;
	}
	if (stack_size % 2 == 0)
		i--;
	while (--i > 0)
	{
		tmp->steps = i;
		tmp->rotate = -1;
		tmp = tmp->next;
	}
}

void	push_element_to_a(t_stacks *s, t_global *g, t_steps *steps)
{
	while (steps->size_a > 0)
	{
		if (steps->rotate_a == 1)
			command_ra(&s, g, 1);
		else
			command_rra(&s, g, 1);
		steps->size_a--;
	}
	while (steps->size_b > 0)
	{
		if (steps->rotate_b == 1)
			command_rb(&s, g, 1);
		else
			command_rrb(&s, g, 1);
		steps->size_b--;
	}
	command_pa(s, &g, 1);
}

int		get_index_of_min_element(t_stack *a, int min)
{
	int i;

	i = 0;
	while (a)
	{
		if (a->data == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

void	my_sort(t_stacks *s, t_global *g)
{
	t_steps *steps;

	if (!(steps = (t_steps *)malloc(sizeof(t_steps))))
		exit(1);
	while (g->size_b > 0)
	{
		steps->size_a = -1;
		steps->size_b = -1;
		set_number_of_steps_to_top(s->a, g->size_a);
		set_number_of_steps_to_top(s->b, g->size_b);
		find_element_to_push_a(s, steps, g->size_a);
		push_element_to_a(s, g, steps);
	}
	if ((get_index_of_min_element(s->a, g->min)) > g->size_a / 2)
	{
		while (s->a->data != g->min)
			command_rra(&s, g, 1);
	}
	else
		while (s->a->data != g->min)
			command_ra(&s, g, 1);
	free(steps);
}

void	main_sort(t_stacks *s, t_global *g)
{
	while (g->size_a > 2)
	{
		if (s->a->data != g->min && s->a->data != g->max)
		{
			command_pb(s, &g, 1);
			if (s->b->data > g->avg)
				command_rb(&s, g, 1);
		}
		else
			command_ra(&s, g, 1);
	}
	if (s->a->data < s->a->next->data)
		command_sa(s, g, 1);
	command_pa(s, &g, 1);
	my_sort(s, g);
}
