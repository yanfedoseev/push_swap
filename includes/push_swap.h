/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:43:48 by doberyn           #+#    #+#             */
/*   Updated: 2019/12/22 14:43:49 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAXINT 2147483647
# define MININT -2147483648
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

// typedef struct		s_data
// {
// 	int				a[10000];
// 	int				count_element;
// }					t_data;

typedef struct		s_stack
{
	int				data;
	int				step;
	int				rotate;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

typedef struct		s_global
{
	int				size_a;
	int				size_b;
	int				min;
	int				max;
	int				avg;
	// t_stack			*a;
	// t_stack			*b;
}					t_global;

typedef struct		s_steps
{
	int				size_a;
	int				size_b;
	int				dest_a;
	int				dest_b;
}					t_steps;



/*
**		push_swap.c - Начало
**			༺༻
**		Нормы:		✓
**			༺༻
*/

int					ft_only_spaces(const char *str);
// int					ft_is_sorted(t_data *new);
void				command_rrr(t_stacks *s, int i);

/*
**		validation.c - Валидация
**			༺༻
**		Нормы:		✓
**			༺༻
*/

int					validation(int argc, char **argv);
void				ft_number_availability(const char *str);
void				ft_valid_str(const char *str);
// void				ft_duplicate_check(t_data *new, t_global *g);
// void				ft_search_duplicate(const int *dup, int count);

/*
**		separation.c - Разбивка массива
**			༺༻
**		Нормы:		✓
**			༺༻
*/

// void				ft_array_separation(int argc, char **argv, t_data *new);
// void				ft_stacking(t_data *new, int *buff, int count);

/*
**		initialization.c - Инициализация стека
**			༺༻
**		Нормы:		✓
**			༺༻
*/

// void				ft_init_stack(t_data *new, t_global *g);
t_stack				*ft_create_stack(const int *buff, int count);
void				free_data(t_stacks *s, t_global *g);
void				ft_sort(t_stacks *s, t_global *g);
void				ft_null(t_global *g);

/*
**		sort_3_and_5_element.c - Сортировка 5-и и меньше чисел.
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_sort_3_element(t_stacks *s, int size_a);
void				ft_sort_5_element(t_stacks *s, t_global *g);
int					ft_max(t_stack *s);

/*
**		 quick_sort.c - Алгоритм быстрой сортировки
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_quick_sort(int *array, int start, int end);
int					command_partition(int *array, int start, int end);

/*
**		 global_sort.c - Алгоритм для сортировки любого количества чисел
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_global_sort(t_stacks *s, t_global *g);
void				ft_start_sort(t_stacks *s, t_global *g);
void				ft_steps_markup(t_stack *stack, int count);
void				ft_minimum_insertion_steps(t_stacks *s, t_steps *steps, int size_a);
void				ft_instruction_execution(t_stacks *s, t_global *g, t_steps *steps);

/*
**		 finding_place.c - Основная часть главного алгоритма
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_help_finding_place(t_stacks *s, int *action, int *buff);
int					ft_finding_place(t_stacks *s, t_steps *steps, int size_a, int min);
int					ft_smaller_element_detection(t_stack *a, int buff, int src);
int					ft_count_to_min(t_stack *a, int min);

/*
**		 actions.c - Действия
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				command_ra(t_stack **a, int i);
void				command_rb(t_stack **b, int i);
void				command_rr(t_stacks *s, int i);
void				command_rra(t_stack **a, int i);
void				command_rrb(t_stack **b, int i);

/*
**		 actions_2.c - Действия
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				command_sa(t_stack *a, int i);
void				command_sb(t_stack *a, int i);
void				command_ss(t_stacks *s, int i);
void				command_pa(t_stacks *s, t_global *g, int i);
void				command_pb(t_stacks *s, t_global *g, int i);

/*
**		 checker.c - Чекер
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				read_command(t_stacks *stacks, t_global *g, char *line);
void				get_commands(t_stacks *stacks, t_global *g);
int					check_if_sorted(t_stack *a);



void				my_exit(int i);
// void				ft_sort(t_global *g);
void				ft_skip(char const *str, char c, int *i);
char				*ft_word(char const *str, char c, int *i);
int					tmp_ft_count_words(char const *str, char c);
char				**tmp_ft_strsplit(char const *s, char c);
int					add_data(int *input, int *tmp, int size);
int					get_args(int *input, int ac, char **av);
t_stack				*create_stack(int *input, int size);
int					sort_input(int *input);
int					init(t_stacks *stacks, t_global *g, int *input, int i);
void				error_msg(int i);

#endif
