#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAXINT 2147483647
# define MININT -2147483648
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

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
	int			color;
	int				size_a;
	int				size_b;
	int				min;
	int				max;
	int				avg;
}					t_global;

typedef struct		s_steps
{
	int				size_a;
	int				size_b;
	int				dest_a;
	int				dest_b;
}					t_steps;

int					ft_only_spaces(const char *str);

t_stack				*ft_create_stack(const int *buff, int count);
void				free_data(t_stacks *s, t_global *g);
void				sort(t_stacks *s, t_global *g);
void				ft_null(t_global *g);

void				sort_3_element(t_stacks *s, int size_a, int color);
void				sort_5_element(t_stacks *s, t_global *g);
int					ft_max(t_stack *s);

void				ft_quick_sort(int *array, int start, int end);
int					command_partition(int *array, int start, int end);

void				global_sort(t_stacks *s, t_global *g);
void				ft_start_sort(t_stacks *s, t_global *g);
void				ft_steps_markup(t_stack *stack, int count);
void				ft_minimum_insertion_steps(t_stacks *s, t_steps *steps, int size_a);
void				ft_instruction_execution(t_stacks *s, t_global *g, t_steps *steps);

void				ft_help_finding_place(t_stacks *s, int *action, int *buff);
int					ft_finding_place(t_stacks *s, t_steps *steps, int size_a, int min);
int					ft_smaller_element_detection(t_stack *a, int buff, int src);
int					ft_count_to_min(t_stack *a, int min);

void				command_ra(t_stack **a, int display, int color);
void				command_rb(t_stack **b, int display, int color);
void				command_rr(t_stacks *s, int display, int color);
void				command_rra(t_stack **a, int display, int color);
void				command_rrb(t_stack **b, int display, int color);

void				command_sa(t_stack *a, int display, int color);
void				command_sb(t_stack *a, int display, int color);
void				command_ss(t_stacks *s, int display, int color);
void				command_pa(t_stacks *s, t_global **g, int display, int color);
void				command_pb(t_stacks *s, t_global **g, int display, int color);

void				command_rrr(t_stacks *s, int display, int color);


void				read_command(t_stacks *stacks, t_global *g, char *line);
void				get_commands(t_stacks *stacks, t_global *g);
int					check_if_sorted(t_stack *a);

void				my_exit(int i);
int					add_data(int *input, int *tmp, int size);
int					get_args(int *input, int ac, char **av, int color);
t_stack				*create_stack(int *input, int size);
int					sort_input(int *input);
int					init(t_stacks *stacks, t_global *g, int *input, int i);
void				error_msg(int i);
int					validation(int ac, char **av, int color);
void				write_command(char *str, int color);

#endif
