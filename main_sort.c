#include "push_swap.h"

/*
**		main_sort - алгоритм для сортировки
**		чисел любого размера написан на базе
** 		сортировки вставками. Данная функция
** 		подготавливает стек к сортировке.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	main_sort(t_stacks *s, t_global *g)
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
	my_sort(s, g);
}

/*
**		my_sort - запуск процесса сортировки.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	my_sort(t_stacks *s, t_global *g)
{
	t_steps *step;

	if (!(step = (t_steps *)malloc(sizeof(t_steps))))
		exit(1);
	while (g->size_b > 0)
	{
		step->size_a = -1;
		step->size_b = -1;
		set_number_of_steps_to_top(s->a, g->size_a);
		set_number_of_steps_to_top(s->b, g->size_b);
		find_element_to_push_a(s, step, g->size_a);
		push_element_to_a(s, g, step);
	}
	// get_index_of_min_element возвращает положение минимального элемента в стеке
	if ((get_index_of_min_element(s->a, g->min)) > g->size_a / 2)
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
**		find_element_to_push_a - функция которая находит
**		элемент который можно перебросить минимальным количеством шагов.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	find_element_to_push_a(t_stacks *s, t_steps *steps, int size_a)
{
	int		min_action;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	min_action = -1;
	tmp_a = s->a;
	tmp_b = s->b;
	while (s->b)
	{
		element_search(s, steps, size_a, &min_action);
		s->a = tmp_a;
		s->b = s->b->next;
	}
	s->b = tmp_b;
}

/*
**		push_element_to_a - функция которая
** 		выполняет действия по заданным ранее параментрам.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	push_element_to_a(t_stacks *s, t_global *g, t_steps *steps)
{
	while (steps->size_a > 0)
	{
		if (steps->rotate_a == 1)
			command_ra(&s, g, 1);
		else
			command_rra(&s, g, 1);
		steps->size_a--;
	}
	while (steps->size_b > 0)
	{
		if (steps->rotate_b == 1)
			command_rb(&s, g, 1);
		else
			command_rrb(&s, g, 1);
		steps->size_b--;
	}
	command_pa(s, &g, 1);
}

/*
**		get_number_of_steps - Вспомогательная функция для
**		element_search. В данной функции происходит поиск
**		наилучшей позиции для вставки.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	get_number_of_steps(t_stacks *s, int *action)
{
	while (s->a)
	{
		if (s->b->data > s->a->data)
		{
			(*action)++;
			if (s->b->data < s->a->next->data)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
}

/*
**		element_search - Функция после нахождения места вставки
**		записывает данные в структуру steps, которая после выполнится
**		в функции push_element_to_a тем самым вставит элемент
** 		в нужное место с наименьшим количеством действий.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	element_search(t_stacks *s, t_steps *steps, int size_a, int *min)
{
	int action;

	action = 0;
	// считаем action - сколько действий потребуется
	// для вставки первого элемента из В в нужное место в А
	get_number_of_steps(s, &action);
	if (s->a->rotate == -1)
		action = size_a - action;
	if (*min == -1 || (action + s->b->step) < *min)
	{
		steps->size_a = action;
		steps->size_b = s->b->step;
		steps->rotate_a = s->a->rotate;
		steps->rotate_b = s->b->rotate;
		*min = action + s->b->step;
	}
}

/*
**		get_index_of_min_element - Функция возвращает
** 		положение минимального элемента(числа) в стеке.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

int		get_index_of_min_element(t_stack *a, int min)
{
	int i;

	i = 0;
	while (a)
	{
		if (a->data == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}
