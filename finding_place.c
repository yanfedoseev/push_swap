#include "push_swap.h"

/*
**		ft_help_finding_place - Вспомогательная функция для
**		ft_finding_place. В данной функции происходит поиск
**		наилучшей позиции для вставки.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_help_finding_place(t_stacks *s, int *action, int *data)
{
	while (s->a)
	{
		*data = s->a->data;
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
	// if (ft_smaller_element_detection(s->a, *data, s->b->data) == 1)
	// {
	// 	while (s->a)
	// 	{
	// 		if (s->a->data < *data && s->a->data > s->b->data)
	// 			break ;
	// 		(*action)++;
	// 		s->a = s->a->next;
	// 	}
	// }
}

/*
**		ft_finding_place - Функция после нахождения места вставки
**		записывает данные в структуру steps, которая после выполнится
**		в функции ft_instruction_execution тем самым вставит элемент
** 		в нужное место с наименьшим количеством действий.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

int		ft_finding_place(t_stacks *s, t_steps *steps, int size_a, int min)
{
	int action;
	int res;
	int buff;

	action = 0;
	buff = 0;
	ft_help_finding_place(s, &action, &buff);
	if (s->a->rotate == -1)
		action = size_a - action;
	if (min == -1 || (action + s->b->step) < min)
	{
		steps->dest_a = s->a->rotate;
		steps->dest_b = s->b->rotate;
		steps->size_a = action;
		steps->size_b = s->b->step;
		res = action + s->b->step;
	}
	else
		res = min;
	return (res);
}

/*
**		ft_smaller_element_detection - Функция сравнивает
**		найденное место с другими, дабы найти место получше
**		куда можно вставить элемент.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

// int		ft_smaller_element_detection(t_stack *a, int buff, int src)
// {
// 	t_stack	*tmp;

// 	tmp = a;
// 	while (tmp)
// 	{
// 		if (tmp->data < buff && tmp->data > src)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

/*
**		ft_count_to_min - Функция возвращает
** 		положение минимального элемента(числа) в стеке.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

int		ft_count_to_min(t_stack *a, int min)
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
