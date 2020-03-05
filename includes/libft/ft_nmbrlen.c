/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:57:32 by gmarin            #+#    #+#             */
/*   Updated: 2019/05/09 15:22:44 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nmbrlen(int n)
{
	int		tmp;
	int		len;

	tmp = n;
	len = 1;
	while (tmp / 10 != 0)
	{
		tmp /= 10;
		len++;
	}
	return ((n < 0) ? len + 1 : len);
}