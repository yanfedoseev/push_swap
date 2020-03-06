/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:09:57 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 21:09:59 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	adopting string according to displaying rules for hash flag
**	Entry:
**		custom structure - format (carrier for general displaying settings).
**	Exit:
**		0 - exception behaviour encountered,
**		1 - processed successfully.
*/

int		apply_hash(t_format *format)
{
	if ((format->type == 'x' || format->type == 'X') \
		&& ft_strcmp("0", format->content.string2show) \
		&& !(format->content.string2show = join_prefix("0x", format)))
		return (0);
	else if (format->type == 'p' \
		&& !(format->content.string2show = join_prefix("0x", format)))
		return (0);
	else if ((format->type == 'f' || format->type == 'F' || \
		format->type == 'g' || format->type == 'G') \
		&& !format->precision && \
		!(format->content.string2show = join_postfix(format, ".")))
		return (0);
	else if ((format->type == 'o' || format->type == 'O') && \
		format->content.string2show[0] != '0' && \
		!(format->content.string2show = join_prefix("0", format)))
		return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}

/*
**	adopting string according to displaying rules for space flag
**	Entry:
**		custom structure - format (carrier for general displaying settings).
**	Exit:
**		0 - exception behaviour encountered,
**		1 - processed successfully.
*/

int		apply_space(t_format *format)
{
	if (format->type != 'u' && format->type != 'U' && \
		format->type != 'c' && format->type != 'C' && \
		format->type != 's' && format->type != 'S' && \
		format->type != 'o' && format->type != 'O' && \
		format->type != 'x' && format->type != 'X' && \
		format->type != '%')
	{
		if (format->width)
		{
			format->width--;
			if (!apply_width(format))
				return (0);
		}
		if (!(format->content.string2show = join_prefix(" ", format)))
			return (0);
	}
	format->length = ft_strlen(format->content.string2show);
	return (1);
}

/*
**	adopting string according to displaying rules for plus flag
**	Entry:
**		custom structure - format (carrier for general displaying settings).
**	Exit:
**		0 - exception behaviour encountered,
**		1 - processed successfully.
*/

int		apply_plus(t_format *format)
{
	if (format->type == 'c' || format->type == 'C' || \
		format->type == 's' || format->type == 'S')
		return (1);
	if (format->type != 'u' && format->type != 'U' && \
		format->type != 'x' && format->type != 'X' && \
		format->type != 'o' && format->type != 'O' && \
		!(format->content.string2show = \
		join_prefix(&format->content.sign, format)))
		return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}

/*
**	adopting string according to displaying rules for zero flag
**	Entry:
**		custom structure - format (carrier for general displaying settings).
**	Exit:
**		0 - exception behaviour encountered,
**		1 - processed successfully.
*/

int		apply_zero(t_format *format)
{
	if (format->type != 'c' && format->type != 'C' \
		&& (format->content.sign == '-' || format->flag.plus == 't'))
		format->length = ft_strlen(format->content.string2show) + 1;
	if (format->type != 'c' && format->type != 'C' \
		&& format->type != 's' && format->type != 'S' && !apply_width(format))
		return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}

/*
**	adopting string according to displaying rules for activated formatting
**	flags stored in 'format' structure
**	Entry:
**		custom structure - format (carrier for general displaying settings).
**	Exit:
**		0 - exception behaviour encountered,
**		1 - processed successfully.
*/

int		apply_flags(t_format *format)
{
	if ((format->content.sign != '-' && format->flag.plus != 't' \
		&& format->flag.space == 't') && !apply_space(format))
		return (0);
	if (format->flag.hash == 't' && format->flag.zero != 't' \
		&& !apply_hash(format))
		return (0);
	if (format->flag.zero == 't' && format->flag.hash != 't' \
		&& !apply_zero(format))
		return (0);
	if (format->flag.hash == 't' && format->flag.zero == 't')
	{
		if (format->width > 1)
			format->width -= 2;
		if (!apply_zero(format) || !apply_hash(format))
			return (0);
	}
	if ((format->content.sign == '-' || format->flag.plus == 't') \
		&& !apply_plus(format))
		return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}
