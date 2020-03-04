/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:18:43 by gmarin            #+#    #+#             */
/*   Updated: 2019/05/09 14:43:02 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *str, char c)
{
	int		j;

	j = 0;
	while (*str == c)
		str++;
	while (*str)
	{
		j++;
		while (*str != c && *str)
			str++;
		while (*str == c)
			str++;
	}
	return (j);
}
