#include "push_swap.h"

/*
**		ft_only_spaces - Проверяем строку
** 		на наличие разделителей.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

int		ft_only_spaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

/*
**		ft_is_sorted - Проверяем массив
** 		на отсортированность.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

// int		ft_is_sorted(t_data *new)
// {
// 	int i;

// 	i = 0;
// 	while (i < (new->count_element - 1))
// 	{
// 		if (new->a[i] > new->a[i + 1])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }
