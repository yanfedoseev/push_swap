#include "push_swap.h"

void	sort(t_stacks *s, t_global *g)
{
	if (g->size_a <= 3)
		sort_3_element(s, g->size_a, g->color);
	else if (g->size_a <= 5)
		sort_5_element(s, g);
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
	g->color = 0;
	if (!(ft_strcmp(av[1], "-c")))
		g->color = 1;
	// printf("color = %c\n", g->color);
	if (!(validation(ac, av, g->color)))
		error_msg(0);
	if(!(get_args(input, ac, av, g->color)))
		my_exit(0);
	if(!(init(stacks, g, input, 0)))
		my_exit(0);
	sort(stacks, g);
	free_data(stacks, g);
	return (0);
}
