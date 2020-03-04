/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:48:52 by gmarin            #+#    #+#             */
/*   Updated: 2019/05/09 14:49:01 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
