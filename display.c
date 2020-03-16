#include "push_swap.h"

void	display_elem(t_global *g, t_stack ***s)
{
	int	size;

	if (g->visualize_k)
	{
		size = (**s)->size_v;
		while(size--)
			write(1, "=", 1);
		size = MAX_SIZE - (**s)->size_v;
		while(size--)
			write(1, " ", 1);
	}
	else
	{
		size = ft_nmbrlen((**s)->data);
		write(1, ft_itoa((**s)->data), size);
		size = MAX_SIZE - size;
		while(size--)
			write(1, " ", 1);
	}
	**s = (**s)->next;
}

void	display_line(t_global *g, t_stack **a, t_stack **b, int *diff)
{
	int size;

	if (*diff > 0)
	{
		display_elem(g, &a);
		(*diff)--;
	}
	else
	{
		size = MAX_SIZE;
		while(size--)
			write(1, " ", 1);
	}
	write(1, "\t\t\t\t", 4);
	if (*diff < 0)
	{
		display_elem(g, &b);
		(*diff)++;
	}
	write(1, "\n", 1);
}

void	display_rest(t_global *g, t_stack **a, t_stack **b)
{
	while (*a)
	{
		display_elem(g, &a);
		write(1, "\t\t\t\t", 4);
		display_elem(g, &b);
		write(1, "\n", 1);
	}
}

void	display_stacks(t_stacks *stacks, t_global *g)
{
	t_stack	*a;
	t_stack	*b;
	int		diff;

	if (g->visualize)
	{
		usleep(100000);
		write(1, "\e[1;1H\e[2J", 10);
	}
	a = stacks->a;
	b = stacks->b;
	diff = g->size_a - g->size_b;
	while (diff)
		display_line(g, &a, &b, &diff);
	display_rest(g, &a, &b);
}

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
