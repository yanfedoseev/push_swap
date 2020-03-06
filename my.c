#include "push_swap.h"

long long	ps_atoi(const char *str)
{
	long long		n;
	int				sign;

	n = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		n = n * 10 + *str++ - '0';
		if (n * sign > MAXINT || n * sign < MININT)
			error_msg(0);
	}
	return (n * sign);
}

int		add_data(int *input, int *tmp, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (++j < input[0] + 1)
			if (tmp[i] == input[j])
				error_msg(0);
		input[j] = tmp[i];
		input[0]++;
	}
	free(tmp);
	return (1);
}

int		get_args(int *input, int ac, char **av, t_global *g)
{
	char		**str;
	int			nmbr;
	int 		i;
	int			j;
	int			*tmp;

	i = 0 + g->color + g->visualize + g->visualize_k + g->file;
	while (++i < ac)
	{
		nmbr = ft_count_words(av[i], ' ');
		str = ft_strsplit(av[i], ' ');
		if (!(tmp = (int *)malloc(sizeof(int) * (nmbr))))
			return (0);
		j = -1;
		while (++j < nmbr)
		{
			tmp[j] = ps_atoi(str[j]);
			free(str[j]);
		}
		free(str);
		if (!(add_data(input, tmp, nmbr)))
			return (0);
	}
	return (1);
}

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
	int	i;
	int size;
	int	tmp;
	int	is_not_sorted;

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
		g->visualize_k = 1;
	else if (!(ft_strcmp(opt, "-f")))
	{
		g->file = 1;
		remove("my_file");
		g->fd = open("my_file", O_WRONLY | O_CREAT);
	}
}

void	set_size_for_visualizer(t_stacks *s, int *input)
{
	int			i;
	t_stack		*start;

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

void	free_data(t_stacks *s, t_global *g)
{
	int		i;
	t_stack	*buff;

	i = 0;
	while (i < g->size_a)
	{
		buff = s->a;
		s->a = s->a->next;
		free(buff);
		i++;
	}
	i = 0;
	while (i < g->size_b)
	{
		buff = s->b;
		s->b = s->b->next;
		free(buff);
		i++;
	}
	if (g->file)
		close(g->fd);
	free(g);
}