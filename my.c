#include "push_swap.h"

void	ft_skip(char const *str, char c, int *i)
{
	while (str[*i] == c)
		(*i)++;
}

char	*ft_word(char const *str, char c, int *i)
{
	char	*wrd;
	int 	k;

	k = *i;
	while (str[k] != c && str[k] != '\0')
		k++;
	if(!(wrd = malloc(sizeof(char) * (k + 1))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i] != '\0')
		wrd[k++] = str[(*i)++];
	wrd[k] = '\0';
	return (wrd);
}

int		tmp_ft_count_words(char const *str, char c)
{
	int		j;

	j = 0;
	while (*str == c)
		str++;
	while (*str)
	{
		j++;
		while (*str != c && *str)
			str++;
		while (*str == c)
			str++;
	}
	return (j);
}

char	**tmp_ft_strsplit(char const *s, char c)
{
	char	**res;
	int 	i;
	int 	j;

	if (s == NULL)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (tmp_ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	ft_skip(s, c, &i);
	while (s[i] != '\0')
	{
		res[j++] = ft_word(s, c, &i);
		if (res[j - 1] == NULL)
		{
			return (NULL);
		}
		ft_skip(s, c, &i);
	}
	res[j] = NULL;
	return (res);
}

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

int		get_args(int *input, int ac, char **av)
{
	char		**str;
	int			nmbr;
	int 		i;
	int			j;
	int			*tmp;

	i = 0;
	while (++i < ac)
	{
		nmbr = tmp_ft_count_words(av[i], ' ');
		str = tmp_ft_strsplit(av[i], ' ');
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

int		init(t_stacks *stacks, t_global *g, int *input, int i)
{
	stacks->a = create_stack(input, input[0]);
	// g->b = NULL;
	g->size_a = input[0];
	g->size_b = 0;
	if (!(sort_input(input)) && !i)
		return (0);
	g->min = input[1];
	g->max = input[input[0]];
	g->avg = input[input[0] / 2 + 1];

	return (1);
}

void	free_data(t_stacks *s, t_global *g)
{
	int		i;
	t_stack	*buff;

	i = 0;

	// buff = s->a;
	// while (buff)
	// {
	// 	printf("data = %i\n", buff->data);
	// 	buff = buff->next;
	// }
	
	// puts("OK");
	// printf("size a = %i\n", g->size_a);
	while (i < g->size_a)
	{
		// puts("OK");
		buff = s->a;
		s->a = s->a->next;
		// printf("buff data = %i\n", buff->data);
		free(buff);
		i++;
	}
	i = 0;
	// puts("OK");
	while (i < g->size_b)
	{
		buff = s->b;
		s->b = s->b->next;
		free(buff);
		i++;
	}
	free(g);
}