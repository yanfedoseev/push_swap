#include "push_swap.h"

void	free_memory(t_stacks *s, t_global *g)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (i < g->size_a)
	{
		tmp = s->a;
		s->a = s->a->next;
		free(tmp);
		i++;
	}
	i = 0;
	while (i < g->size_b)
	{
		tmp = s->b;
		s->b = s->b->next;
		free(tmp);
		i++;
	}
	free(s);
	if (g->file)
		close(g->fd);
	free(g);
}
