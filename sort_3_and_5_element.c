#include "push_swap.h"

/*
**		sort_3_element - алгоритм для сортировки 3-х
**		и 2-х чисел.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	sort_3_element(t_stacks *s, t_global *g)
{
	int max;

	max = ft_max(s->a);
	if (g->size_a == 1)
		return ;
	else if (g->size_a == 2)
	{
		if (s->a->data > s->a->next->data)
			command_sa(s, g, 1);
		return ;
	}
	else if (g->size_a == 3)
	{
		if (s->a->data == max)
			command_ra(&s, g, 1);
		if (s->a->next->data == max)
			command_rra(&s, g, 1);
		if (s->a->data > s->a->next->data)
			command_sa(s, g, 1);
	}
}

/*
**		sort_5_element - алгоритм для сортировки 5-ти
**		и 4-х чисел.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	sort_5_element(t_stacks *s, t_global *g)
{
	while (g->size_b < 2)
	{
		if (s->a->data == g->min || s->a->data == g->max)
			command_pb(s, &g, 1);
		else
			command_ra(&s, g, 1);
	}
	sort_3_element(s, g);
	command_pa(s, &g, 1);
	command_pa(s, &g, 1);
	if (s->a->data == g->max)
	{
		command_ra(&s, g, 1);
	}
	else
	{
		command_sa(s, g, 1);
		command_ra(&s, g, 1);
	}
}

/*
**		ft_max - функция возвращает максимальное значение
**		из стека.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

int		ft_max(t_stack *s)
{
	int max;

	max = s->data;
	while (s)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}
