/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 02:23:05 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/29 02:23:06 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_percent(t_spec *spec)
{
	char	buf[2];

	buf[0] = '%';
	buf[1] = '\0';
	spec->p = ft_strdup(buf);
	if (!spec->p)
		return (0);
	if (!ft_get_padded_string(spec, 1, ' '))
		return (0);
	return (1);
}
