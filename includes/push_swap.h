#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAXINT 2147483647
# define MININT -2147483648
# define MAX_SIZE 8
# include <unistd.h>
// # include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct		s_stack
{
	int				data;
	int				step;
	int				rotate;
	int				size_v;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

typedef struct		s_global
{
	int				color;
	int				visualize;
	int				visualize_k;
	int				file;
	int				fd;
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
	int				rotate_a;
	int				rotate_b;
}					t_steps;

int					ft_only_spaces(const char *str);

t_stack				*ft_create_stack(const int *buff, int count);
void				free_memory(t_stacks *s, t_global *g);
void				sort(t_stacks *s, t_global *g);
void				ft_null(t_global *g);

void				sort_3(t_stacks *s, t_global *g);
void				sort_5(t_stacks *s, t_global *g);
int					get_max(t_stack *s);

void				ft_quick_sort(int *array, int start, int end);
int					command_partition(int *array, int start, int end);

void				main_sort(t_stacks *s, t_global *g);
void				my_sort(t_stacks *s, t_global *g);
void				set_number_of_steps_to_top(t_stack *s, int stack_size);
void				find_element_to_push_a(t_stacks *s, \
						t_steps *steps, int size_a);
void				push_element_to_a(t_stacks *s, \
						t_global *g, t_steps *steps);

// void				get_number_of_steps(t_stacks *s, int *action, int *buff);
void				get_number_of_steps(t_stacks *s, int *action);
void				element_search(t_stacks *s, \
						t_steps *steps, int size_a, int *min);
int					ft_smaller_element_detection(t_stack *a, int buff, int src);
int					get_index_of_min_element(t_stack *a, int min);

void				command_ra(t_stacks **s, t_global *g, int display);
void				command_rb(t_stacks **s, t_global *g, int display);
void				command_rr(t_stacks *s, t_global *g, int display);
void				command_rra(t_stacks **s, t_global *g, int display);
void				command_rrb(t_stacks **s, t_global *g, int display);

void				command_sa(t_stacks *s, t_global *g, int display);
void				command_sb(t_stacks *s, t_global *g, int display);
void				command_ss(t_stacks *s, t_global *g, int display);
void				command_pa(t_stacks *s, t_global **g, int display);
void				command_pb(t_stacks *s, t_global **g, int display);

void				command_rrr(t_stacks *s, t_global *g, int display);


void				read_command(t_stacks *stacks, t_global *g, char *line);
void				get_commands(t_stacks *stacks, t_global *g);
int					check_if_sorted(t_stack *a);

void				my_exit(int i);
int					add_data(int *input, int *tmp, int size);
int					get_args(int *input, int ac, char **av, t_global *g);
t_stack				*create_stack(int *input, int size);
int					sort_input(int *input);
int					init(t_stacks *stacks, t_global *g, int *input, int i);
void				error_msg(int i);
int					validation(int ac, char **av, t_global *g);
void				write_command(char *str, t_global *g);
void				not_error_but_bonus(t_stacks *stacks, \
						t_global *g, char *line);
void				display_stacks(t_stacks *stacks, t_global *g);
void				init_global(t_global *g, char *opt);
void				set_size_for_visualizer(t_stacks *s, int *input);

#endif
