#include "push_swap.h"

int		validation(int ac, char **av, int color)
{
	int i;
	int	j;

	j = color;
	while (++j < ac)
	{
		i = -1;
		while (av[j][++i] != '\0')
		{
			if ((av[j][i] == '-' || av[j][i] == '+') && av[j][i + 1] >= '0' && av[j][i + 1] <= '9')
				continue ;
			else if (av[j][i] != ' ' && (av[j][i] < '0' || av[j][i] > '9'))
				return (0);
		}
	}
	return (1);
}

