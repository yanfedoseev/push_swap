/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:22:12 by gmarin            #+#    #+#             */
/*   Updated: 2019/05/09 15:46:47 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*mydest;
	const unsigned char		*mysrc;

	mydest = dest;
	mysrc = src;
	while (n--)
	{
		*mydest++ = *mysrc;
		if (*mysrc == (unsigned char)c)
			return ((void*)mydest);
		mysrc++;
	}
	return (NULL);
}
