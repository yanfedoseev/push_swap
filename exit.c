#include "push_swap.h"

void	error_msg(int i)
{
	write(2, "Error\n", 6);
	my_exit(i);
}

void	my_exit(int i)
{
	exit(i);
}
