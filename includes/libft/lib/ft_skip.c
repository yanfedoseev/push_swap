#include "../libft.h"

void	ft_skip(char const *str, char c, int *i)
{
	while (str[*i] == c)
		(*i)++;
}