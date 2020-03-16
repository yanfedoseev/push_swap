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
	int			i;
	int			j;
	int			*tmp;

	i = 0 + g->color + g->visualize + g->file;
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
