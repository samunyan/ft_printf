/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_diux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:06:23 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/29 00:06:25 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_d(t_spec *spec)
{
	int	d;

	d = va_arg(spec->sap, int);
	if (d == 0 && (spec->flags & PRC) && spec->prc == 0)
		spec->p = ft_strdup("");
	else
		spec->p = ft_itoa(d);
	if (!spec->p)
		return (0);
	if (d >= 0 && ((spec->flags & PLUS) || (spec->flags & SPACE)))
	{
		if (!ft_prepend_sign_or_blank(spec))
		{
			free(spec->p);
			return (0);
		}
	}
	if ((spec->flags & PRC) && !ft_get_precision_fill(spec, d))
		return (0);
	if (!ft_get_zero_or_blank_fill(spec, d))
		return (0);
	return (1);
}

int	ft_convert_u(t_spec *spec)
{
	unsigned int	d;

	d = va_arg(spec->sap, unsigned int);
	if (d == 0 && (spec->flags & PRC) && spec->prc == 0)
		spec->p = ft_strdup("");
	else
		spec->p = ft_utoa(d);
	if (!spec->p)
		return (0);
	if ((spec->flags & PRC) && !ft_get_precision_fill(spec, d))
		return (0);
	if (!ft_get_zero_or_blank_fill(spec, d))
		return (0);
	return (1);
}

int	ft_convert_x_low(t_spec *spec)
{
	unsigned int	h;

	h = va_arg(spec->sap, unsigned int);
	if (h == 0 && (spec->flags & PRC) && spec->prc == 0)
		spec->p = ft_strdup("");
	else
		spec->p = ft_utoa_base(h, BASE_16_LOW);
	if (!spec->p)
		return (0);
	if (h != 0 && (spec->flags & ALT) && !ft_prepend(&(spec->p), "0x"))
		return (0);
	if ((spec->flags & PRC) && !ft_get_precision_fill(spec, h))
		return (0);
	if (!ft_get_zero_or_blank_fill(spec, h))
		return (0);
	return (1);
}

int	ft_convert_x_up(t_spec *spec)
{
	unsigned int	h;

	h = va_arg(spec->sap, unsigned int);
	if (h == 0 && (spec->flags & PRC) && spec->prc == 0)
		spec->p = ft_strdup("");
	else
		spec->p = ft_utoa_base(h, BASE_16_UP);
	if (!spec->p)
		return (0);
	if (h != 0 && (spec->flags & ALT) && !ft_prepend(&(spec->p), "0X"))
		return (0);
	if ((spec->flags & PRC) && !ft_get_precision_fill(spec, h))
		return (0);
	if (!ft_get_zero_or_blank_fill(spec, h))
		return (0);
	return (1);
}
