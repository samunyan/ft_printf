/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_scp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:08:29 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/29 00:08:30 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_s(t_spec *spec)
{
	size_t	n_chars;

	spec->p = va_arg(spec->sap, char *);
	if (!spec->p)
		spec->p = ft_strdup("(null)");
	else
		spec->p = ft_strdup(spec->p);
	if (!spec->p)
		return (0);
	if (spec->flags & PRC)
		n_chars = ft_strnlen(spec->p, spec->prc);
	else
		n_chars = ft_strlen(spec->p);
	if (!ft_get_padded_string(spec, n_chars, ' '))
		return (0);
	return (1);
}

int	ft_convert_c(t_spec *spec)
{
	char	c;

	c = va_arg(spec->sap, int);
	spec->p = malloc(2);
	if (!spec->p)
		return (0);
	spec->p[0] = c;
	spec->p[1] = '\0';
	if (!ft_get_padded_string(spec, 1, ' '))
		return (0);
	return (1);
}

int	ft_convert_p(t_spec *spec)
{
	unsigned long	i;

	i = va_arg(spec->sap, unsigned long);
	spec->p = ft_ultoa_base(i, BASE_16_LOW);
	if (!spec->p || !ft_prepend(&(spec->p), "0x"))
		return (0);
	if (!ft_get_padded_string(spec, ft_strlen(spec->p), ' '))
		return (0);
	return (1);
}
