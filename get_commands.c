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
