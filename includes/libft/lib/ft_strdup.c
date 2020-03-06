/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:27:25 by gmarin            #+#    #+#             */
/*   Updated: 2019/05/02 17:27:27 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s);
	if (!(res =(char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	while (len--)
		res[len] = s[len];
	return (res);
}
