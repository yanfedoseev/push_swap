/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:30:38 by gmarin            #+#    #+#             */
/*   Updated: 2019/05/02 17:30:41 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	if (size > size + 1)
		return (NULL);
	if(!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(res, '\0', size + 1);
	return (res);
}
