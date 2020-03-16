#include "push_swap.h"

int		check_if_sorted(t_stack *a)
{
	int		prev_data;

	while (a->next)
	{
		prev_data = a->data;
		a = a->next;
		if (prev_data > a->data)
			return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stacks	*stacks;
	t_global	*g;
	int			input[30000];

	input[0] = 0;
	if (ac < 2)
		my_exit(0);
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		my_exit(0);
	if (!(g = (t_global *)malloc(sizeof(t_global))))
		my_exit(0);
	init_global(g, av[1]);
	if (!(validation(ac, av, g)))
		error_msg(0);
	get_args(input, ac, av, g);
	if(!(init(stacks, g, input, 1)))
		my_exit(0);
	get_commands(stacks, g);
	if (check_if_sorted(stacks->a) && !g->size_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_memory(stacks, g);
	return (0);
}
