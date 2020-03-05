#include "push_swap.h"

/*
**		global_sort - алгоритм для сортировки
**		чисел любого размера написан на базе
** 		сортировки вставками. Данная функция
** 		подготавливает стек к сортировке.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	global_sort(t_stacks *s, t_global *g)
{
	while (g->size_a > 2)
	{
		if (s->a->data != g->min && s->a->data != g->max)
		{
			command_pb(s, &g, 1, g->color);
			if (s->b->data > g->avg)
				command_rb(&s->b, 1, g->color);
		}
		else
			command_ra(&s->a, 1, g->color);
	}
	if (s->a->data < s->a->next->data)
		command_sa(s->a, 1, g->color);
	command_pa(s, &g, 1, g->color);
	ft_start_sort(s, g);
}

/*
**		ft_start_sort - запуск процесса сортировки.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_start_sort(t_stacks *s, t_global *g)
{
	t_steps *step;

	if (!(step = (t_steps *)malloc(sizeof(t_steps))))
		exit(1);
	while (g->size_b > 0)
	{
		step->size_a = -1;
		step->size_b = -1;
		step->dest_a = 0;
		step->dest_b = 0;
		ft_steps_markup(s->a, g->size_a);
		ft_steps_markup(s->b, g->size_b);
		ft_minimum_insertion_steps(s, step, g->size_a);
		ft_instruction_execution(s, g, step);
	}
	if ((ft_count_to_min(s->a, g->min)) > g->size_a / 2)
	{
		while (s->a->data != g->min)
			command_rra(&s->a, 1, g->color);
	}
	else
		while (s->a->data != g->min)
			command_ra(&s->a, 1, g->color);
	free(step);
}

/*
**		ft_steps_markup - разметка каждого элемента стека
**		количеством шагов которое нужно, чтоб элемент
** 		попал на верх(на первую позицию).
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_steps_markup(t_stack *stack, int count)
{
	int		i;
	int		iter;
	t_stack	*buff;

	i = -1;
	iter = count / 2;
	buff = stack;
	while (++i <= iter)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

/*
**		ft_minimum_insertion_steps - функция которая находит
**		элемент который можно перебросить минимальным количеством шагов.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_minimum_insertion_steps(t_stacks *s, t_steps *steps, int size_a)
{
	int		min_action;
	t_stack	*first_a;
	t_stack	*first_b;

	min_action = -1;
	first_a = s->a;
	first_b = s->b;
	while (s->b)
	{
		min_action = ft_finding_place(s, steps, size_a, min_action);
		s->a = first_a;
		s->b = s->b->next;
	}
	s->b = first_b;
}

/*
**		ft_instruction_execution - функция которая
** 		выполняет действия по заданным ранее параментрам.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_instruction_execution(t_stacks *s, t_global *g, t_steps *steps)
{
	while (steps->size_a > 0)
	{
		if (steps->dest_a == 1)
			command_ra(&s->a, 1, g->color);
		else
			command_rra(&s->a, 1, g->color);
		steps->size_a--;
	}
	while (steps->size_b > 0)
	{
		if (steps->dest_b == 1)
			command_rb(&s->b, 1, g->color);
		else
			command_rrb(&s->b, 1, g->color);
		steps->size_b--;
	}
	command_pa(s, &g, 1, g->color);
}
