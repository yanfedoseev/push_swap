#include "../libft.h"

int		ft_nmbrlen(int n)
{
	int 	tmp;
	int 	len;

	tmp = n;
	len = 1;
	while (tmp / 10 != 0)
	{
		tmp /= 10;
		len++;
	}
	return ((n < 0) ? len + 1 : len);
}