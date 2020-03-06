/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:32:05 by gmarin            #+#    #+#             */
/*   Updated: 2019/05/02 17:32:07 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;

	if (s == NULL)
		return (NULL);
	if(!(res = ft_strnew(len)))
		return (NULL);
	while (len--)
		res[len] = s[start + len];
	return (res);
}
