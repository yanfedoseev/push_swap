/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:16:58 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 21:17:00 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	adopting string according to displaying rules for activated width
**	flag stored in 'format' structure
**	Entry:
**		custom structure - format (carrier for general displaying settings).
**	Exit:
**		0 - exception behaviour encountered,
**		1 - processed successfully.
*/

int		apply_width(t_format *format)
{
	char	*filler_str;
	char	c;
	size_t	i;

	i = 0;
	c = ' ';
	if (format->type == 'c')
		format->length = 1;
	if (format->length < format->width)
	{
		if (!(filler_str = ft_strnew(format->width - format->length)))
			return (0);
		if (format->flag.zero == 't' && format->flag.minus == 'f')
			c = '0';
		while (i < format->width - format->length)
			filler_str[i++] = c;
		if (format->flag.minus == 't')
			format->content.string2show = \
			join_strings(format->content.string2show, filler_str, format);
		else
			format->content.string2show = \
			join_strings(filler_str, format->content.string2show, format);
		format->type == 'c' ? format->length = format->width : 0;
	}
	return (1);
}
