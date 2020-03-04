#include "push_swap.h"

void	ft_sort(t_stacks *s, t_global *g)
{
	if (g->size_a <= 3)
		ft_sort_3_element(s, g->size_a);
	else if (g->size_a <= 5)
		ft_sort_5_element(s, g);
	else
		ft_global_sort(s, g);
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
	if (!(validation(ac, av)))
		error_msg(0);
	if(!(get_args(input, ac, av)))
		my_exit(0);
	if(!(init(stacks, g, input, 0)))
		my_exit(0);
	ft_sort(stacks, g);
	free_data(stacks, g);
	return (0);
}
