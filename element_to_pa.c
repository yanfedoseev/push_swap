#include "push_swap.h"

void	get_number_of_steps(t_stacks *s, int *steps_nmbr)
{
	while (s->a)
	{
		if (s->b->data > s->a->data)
		{
			(*steps_nmbr)++;
			if (s->b->data < s->a->next->data)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
}

void	element_search(t_stacks *s, t_steps *steps, int size_a, int *min_steps)
{
	int steps_nmbr;

	steps_nmbr = 0;
	get_number_of_steps(s, &steps_nmbr);
	if (s->a->rotate == -1)
		steps_nmbr = size_a - steps_nmbr;
	if (*min_steps == -1 || (steps_nmbr + s->b->steps) < *min_steps)
	{
		steps->size_a = steps_nmbr;
		steps->size_b = s->b->steps;
		steps->rotate_a = s->a->rotate;
		steps->rotate_b = s->b->rotate;
		*min_steps = steps_nmbr + s->b->steps;
	}
}

void	find_element_to_push_a(t_stacks *s, t_steps *steps, int size_a)
{
	int		min_steps;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	min_steps = -1;
	tmp_a = s->a;
	tmp_b = s->b;
	while (s->b)
	{
		element_search(s, steps, size_a, &min_steps);
		s->a = tmp_a;
		s->b = s->b->next;
	}
	s->b = tmp_b;
}
