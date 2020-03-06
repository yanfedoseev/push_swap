#include "../libft.h"

void	ft_lstfree(t_list *lst)
{
	t_list	*mylist;
	t_list	*tmp;

	mylist = lst;
	while (mylist)
	{
		tmp = mylist;
		mylist = mylist->next;
		free(tmp);
	}
	lst = NULL;
}