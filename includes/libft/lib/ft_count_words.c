#include "../libft.h"

int		ft_count_words(char const *str, char c)
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