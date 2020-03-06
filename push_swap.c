#include "push_swap.h"

// void clearScreen()
// {
//   sleep(0.1);
//   write(1, "\e[1;1H\e[2J", 10);
// }

void	sort(t_stacks *s, t_global *g)
{
	if (g->size_a <= 3)
		sort_3_element(s, g);
	else if (g->size_a <= 5)
		sort_5_element(s, g);
	else
		global_sort(s, g);
}

// void	check_option(char *opt, t_global *g)
// {
// 	if (!(ft_strcmp(opt, "-c")))
// 		g->color = 1;
// 	else if (!(ft_strcmp(opt, "-v")))
// 		g->visualize = 1;
// 	else if (!(ft_strcmp(opt, "-f")))
// 		g->file = 1;
// }

int		main(int ac, char **av)
{
	t_stacks	*stacks;
	t_global	*g;
	int			input[30000];
	// int			fd;

	// fd = open("file4", O_WRONLY | O_CREAT);
	input[0] = 0;
	if (ac < 2)
		my_exit(0);
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		my_exit(0);
	if (!(g = (t_global *)malloc(sizeof(t_global))))
		my_exit(0);
	init_global(g, av[1]);
	// printf("g->file = %i\n", g->file);
	// check_option(av[1], g);
	if (!(validation(ac, av, g)))
		error_msg(0);
	if(!(get_args(input, ac, av, g)))
		my_exit(0);
	if(!(init(stacks, g, input, 0)))
		my_exit(0);
	// t_stack *tmp;
	// tmp = stacks->a;
	// while (tmp)
	// {
	// 	printf("data = %i    size = %i\n", tmp->data, tmp->size_v);
	// 	tmp = tmp->next;
	// }
	sort(stacks, g);
	free_data(stacks, g);
	// close(fd);
	return (0);
}
