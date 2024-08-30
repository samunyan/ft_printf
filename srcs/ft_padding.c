/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:06:34 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/29 00:06:36 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pad_string_left(t_spec *spec, size_t n_chars, char *s,
								size_t n_fills)
{
	if (ft_memappend((void **)&(spec->buffer), spec->p, spec->n_chars, n_chars))
	{
		spec->n_chars += n_chars;
		ft_memappend((void **)&(spec->buffer), s, spec->n_chars, n_fills);
		spec->n_chars += n_fills;
	}
}

static void	ft_pad_string_right(t_spec *spec, size_t n_chars, char *s,
								size_t n_fills)
{
	if (ft_memappend((void **)&(spec->buffer), s, spec->n_chars, n_fills))
	{
		spec->n_chars += n_fills;
		ft_memappend((void **)&(spec->buffer), spec->p, spec->n_chars, n_chars);
		spec->n_chars += n_chars;
	}
}

char	*ft_get_padded_string(t_spec *spec, size_t n_chars, int c)
{
	size_t	n_fills;
	char	*s;

	if (!(spec->flags & MINFW) || n_chars >= (size_t)spec->minfw)
	{
		ft_memappend((void **)&(spec->buffer), spec->p, spec->n_chars, n_chars);
		spec->n_chars += n_chars;
		free(spec->p);
		return (spec->buffer);
	}
	n_fills = (size_t)spec->minfw - n_chars;
	s = malloc(n_fills);
	if (!s)
	{
		free(spec->p);
		return (NULL);
	}
	ft_memset(s, c, n_fills);
	if (spec->flags & LEFT)
		ft_pad_string_left(spec, n_chars, s, n_fills);
	else
		ft_pad_string_right(spec, n_chars, s, n_fills);
	free(s);
	free(spec->p);
	return (spec->buffer);
}
