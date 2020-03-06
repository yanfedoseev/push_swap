/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:31:55 by gmarin            #+#    #+#             */
/*   Updated: 2019/05/02 17:31:57 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	char	*sub;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		str = (char *)haystack;
		sub = (char *)needle;
		while (*str == *sub && *sub)
		{
			str++;
			sub++;
		}
		if (!*sub)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
