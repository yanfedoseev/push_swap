#include "push_swap.h"

t_stack	*create_stack(int *input, int size)
{
	int			i;
	t_stack		*lst;
	t_stack		*res;

	if (!(lst = (t_stack *)malloc(sizeof(t_stack))))
		return(0);

	res = lst;

	i = 0;
	while (++i < size)
	{
		lst->data = input[i];
		if (!(lst->next = (t_stack *)malloc(sizeof(t_stack))))
			return(0);
		lst = lst->next;
	}
	lst->data = input[i];
	lst->next = NULL;

	return (res);
}

int		sort_input(int *input)
{
	int		i;
	int		size;
	int		tmp;
	int		is_not_sorted;

	is_not_sorted = 0;
	size = input[0];
	while (--size)
	{
		i = 0;
		while (++i <= size)
		{
			if (input[i] > input[i + 1])
			{
				is_not_sorted = 1;
				tmp = input[i];
				input[i] = input[i + 1];
				input[i + 1] = tmp;
			}
		}
	}

	return (is_not_sorted);
}

void	set_size_for_visualizer(t_stacks *s, int *input)
{
	int			i;
	t_stack		*start;


	i = 0;
	start = s->a;
	while (s->a)
	{
		i = 1;
		while (s->a->data != input[i])
			i++;
		s->a->size_v = i;
		if ((s->a->size_v * MAX_SIZE) % input[0])
			s->a->size_v = (int)(s->a->size_v * MAX_SIZE / input[0]) + 1;
		else
			s->a->size_v = s->a->size_v * MAX_SIZE / input[0];
		s->a = s->a->next;
	}
	s->a = start;
}

int		init(t_stacks *stacks, t_global *g, int *input, int i)
{
	stacks->a = create_stack(input, input[0]);
	g->size_a = input[0];
	g->size_b = 0;
	if (!(sort_input(input)) && !i)
		return (0);
	g->min = input[1];
	g->max = input[input[0]];
	g->avg = input[input[0] / 2 + 1];
	if (g->visualize_k)
		set_size_for_visualizer(stacks, input);
	return (1);
}

void	init_global(t_global *g, char *opt)
{
	g->color = 0;
	g->visualize = 0;
	g->visualize_k = 0;
	g->file = 0;
	if (!(ft_strcmp(opt, "-c")))
		g->color = 1;
	else if (!(ft_strcmp(opt, "-v")))
		g->visualize = 1;
	else if (!(ft_strcmp(opt, "-vk")))
	{
		g->visualize = 1;
		g->visualize_k = 1;
	}
	else if (!(ft_strcmp(opt, "-f")))
	{
		g->file = 1;
		g->fd = open("my_file", O_WRONLY | O_CREAT | O_TRUNC);
	}
}
