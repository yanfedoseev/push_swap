#include "push_swap.h"

void	sort(t_stacks *s, t_global *g)
{
	if (g->size_a <= 3)
		sort_3(s, g);
	else if (g->size_a <= 5)
		sort_5(s, g);
	else
		global_sort(s, g);
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
	if(!(get_args(input, ac, av, g)))
		my_exit(0);
	if(!(init(stacks, g, input, 0)))
		my_exit(0);
	sort(stacks, g);
	free_data(stacks, g);
	return (0);
}
