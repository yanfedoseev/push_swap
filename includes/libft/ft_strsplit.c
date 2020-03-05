 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:31:45 by gmarin            #+#    #+#             */
/*   Updated: 2019/05/09 15:13:33 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	ft_skip(s, c, &i);
	while (s[i] != '\0')
	{
		res[j++] = ft_word(s, c, &i);
		if (res[j - 1] == NULL)
		{
			ft_arrfree(res);
			return (NULL);
		}
		ft_skip(s, c, &i);
	}
	res[j] = NULL;
	return (res);
}
