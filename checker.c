#include "push_swap.h"

void	not_error_but_bonus(t_stacks *stacks, t_global *g, char *line)
{
	if (!(ft_strcmp(line, "")))
		display_stacks(stacks, g);
	else
		error_msg(1);
}

void	read_command(t_stacks *stacks, t_global *g, char *line)
{
	if (!(ft_strcmp(line, "sa")))
		command_sa(stacks, g, 0);
	else if (!(ft_strcmp(line, "sb")))
		command_sb(stacks, g, 0);
	else if (!(ft_strcmp(line, "ss")))
		command_ss(stacks, g, 0);
	else if (!(ft_strcmp(line, "pa")))
		command_pa(stacks, &g, 0);
	else if (!(ft_strcmp(line, "pb")))
		command_pb(stacks, &g, 0);
	else if (!(ft_strcmp(line, "ra")))
		command_ra(&stacks, g, 0);
	else if (!(ft_strcmp(line, "rb")))
		command_rb(&stacks, g, 0);
	else if (!(ft_strcmp(line, "rr")))
		command_rr(stacks, g, 0);
	else if (!(ft_strcmp(line, "rra")))
		command_rra(&stacks, g, 0);
	else if (!(ft_strcmp(line, "rrb")))
		command_rrb(&stacks, g, 0);
	else if (!(ft_strcmp(line, "rrr")))
		command_rrr(stacks, g, 0);
	else
		not_error_but_bonus(stacks, g, line);
}

void	get_commands(t_stacks *stacks, t_global *g)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		read_command(stacks, g, line);
		free(line);
	}
}

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
	free_data(stacks, g);
	return (0);
}
