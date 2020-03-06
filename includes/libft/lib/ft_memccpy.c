/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:22:12 by gmarin            #+#    #+#             */
/*   Updated: 2019/05/02 17:22:18 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*mydest;
	unsigned char	*mysrc;

	mydest = (unsigned char *)dest;
	mysrc = (unsigned char *)src;
	while (*mysrc != c && --n)
	{
		*mydest++ = *mysrc++;
	}
	if (n)
	{
		*mydest++ = *mysrc++;
		return ((void *)mydest);
	}
	return (NULL);
}