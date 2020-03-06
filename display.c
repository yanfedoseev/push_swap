#include "push_swap.h"

void	display_stacks(t_stacks *stacks, t_global *g)
{
	t_stack	*a;
	t_stack	*b;
	int		diff;

	if (g->visualize)
	{
        usleep(200000);
		write(1, "\e[1;1H\e[2J", 10);
	}
	a = stacks->a;
	b = stacks->b;
	diff = g->size_a - g->size_b;
	if (g->size_a > g->size_b)
	{
		while (diff--)
		{
			ft_printf("%i\t\t\n", a->data);
			a = a->next;
		}
		
	}
	else if (g->size_a < g->size_b)
	{
		while (diff++)
		{
			ft_printf("\t\t%i\n", b->data);
			b = b->next;
		}
	}
	while (a)
	{
		ft_printf("%i\t\t%i\n", a->data, b->data);
		a = a->next;
		b = b->next;
	}
}