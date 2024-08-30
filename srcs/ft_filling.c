/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:06:34 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/29 00:06:36 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_precision_fill(t_spec *spec, long d)
{
	size_t	len;

	if (d < 0)
		ft_memmove(spec->p, spec->p + 1, ft_strlen(spec->p));
	len = ft_strlen(spec->p);
	while (spec->prc > (int)len)
	{
		if (!ft_prepend(&(spec->p), "0"))
		{
			free(spec->p);
			return (0);
		}
		spec->prc--;
	}
	if (d < 0 && !ft_prepend(&(spec->p), "-"))
	{
		free(spec->p);
		return (0);
	}
	return (1);
}

int	ft_get_zero_or_blank_fill(t_spec *spec, long d)
{
	char	fill_c;

	if (spec->flags & ZERO)
	{
		if (d < 0)
		{
			ft_memmove(spec->p, spec->p + 1, ft_strlen(spec->p));
			if (!ft_memappend((void **)&(spec->buffer), "-", spec->n_chars, 1))
			{
				free(spec->p);
				return (0);
			}
			if (spec->minfw > 0)
				spec->minfw--;
			spec->n_chars++;
		}
		fill_c = '0';
	}
	else
		fill_c = ' ';
	if (!ft_get_padded_string(spec, ft_strlen(spec->p), fill_c))
		return (0);
	return (1);
}

int	ft_prepend_sign_or_blank(t_spec *spec)
{
	char	*s;

	if (spec->flags & PLUS)
		s = "+";
	else if (spec->flags & SPACE)
		s = " ";
	if ((spec->flags & PRC) || (spec->flags & ZERO))
	{
		if (!ft_memappend((void **)&(spec->buffer), s, spec->n_chars, 1))
			return (0);
		spec->n_chars++;
		if (spec->minfw > 0)
			spec->minfw--;
	}
	else
	{
		if (!ft_prepend(&(spec->p), s))
			return (0);
	}
	return (1);
}
