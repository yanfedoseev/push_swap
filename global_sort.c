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
			command_pb(s, &g, 1);
			if (s->b->data > g->avg)
				command_rb(&s, g, 1);
		}
		else
			command_ra(&s, g, 1);
	}
	if (s->a->data < s->a->next->data)
		command_sa(s, g, 1);
	command_pa(s, &g, 1);
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
		set_number_of_steps_to_top(s->a, g->size_a);
		set_number_of_steps_to_top(s->b, g->size_b);
		ft_minimum_insertion_steps(s, step, g->size_a);
		ft_instruction_execution(s, g, step);
	}
	if ((ft_count_to_min(s->a, g->min)) > g->size_a / 2)
	{
		while (s->a->data != g->min)
			command_rra(&s, g, 1);
	}
	else
		while (s->a->data != g->min)
			command_ra(&s, g, 1);
	free(step);
}

/*
**		set_number_of_steps_to_top - разметка каждого элемента стека
**		количеством шагов которое нужно, чтоб элемент
** 		попал на верх(на первую позицию).
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	set_number_of_steps_to_top(t_stack *s, int stack_size)
{
	int		i;
	t_stack	*tmp;

	tmp = s;
	i = -1;
	while (++i <= stack_size / 2)
	{
		tmp->step = i;
		tmp->rotate = 1;
		tmp = tmp->next;
	}
	if (stack_size % 2 == 0)
		i--;
	while (--i > 0)
	{
		tmp->step = i;
		tmp->rotate = -1;
		tmp = tmp->next;
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
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	min_action = -1;
	tmp_a = s->a;
	tmp_b = s->b;
	while (s->b)
	{
		min_action = ft_finding_place(s, steps, size_a, min_action);
		s->a = tmp_a;
		s->b = s->b->next;
	}
	s->b = tmp_b;
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
			command_ra(&s, g, 1);
		else
			command_rra(&s, g, 1);
		steps->size_a--;
	}
	while (steps->size_b > 0)
	{
		if (steps->dest_b == 1)
			command_rb(&s, g, 1);
		else
			command_rrb(&s, g, 1);
		steps->size_b--;
	}
	command_pa(s, &g, 1);
}
