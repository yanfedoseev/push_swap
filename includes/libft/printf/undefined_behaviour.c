/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined_behaviour.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:45:02 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 20:45:03 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		undefined_behaviour(t_format *format)
{
	if (!(format->content.string2show = ft_strdup(&format->type)))
		return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}
