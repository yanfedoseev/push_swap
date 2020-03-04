/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:30:53 by gmarin            #+#    #+#             */
/*   Updated: 2019/05/09 15:11:07 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*sub;
	size_t	tmp;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		str = (char *)haystack;
		sub = (char *)needle;
		tmp = len;
		while (*str == *sub && *sub && tmp)
		{
			str++;
			sub++;
			tmp--;
		}
		if (!*sub)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
