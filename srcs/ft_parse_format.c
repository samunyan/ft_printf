/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:26:58 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/12 13:26:59 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(const char *fmt, t_spec *spec)
{
	const char	*s;

	s = fmt;
	while (*fmt)
	{
		while (*s && *s != '%')
			s++;
		if ((s != fmt && !ft_memappend((void **)&(spec->buffer),
					fmt, spec->n_chars, s - fmt)))
			return (-1);
		spec->n_chars += (s - fmt);
		if (spec->n_chars > (size_t)INT32_MAX)
			return (-1);
		if (*s == '%')
		{
			s++;
			if (!ft_strchr(ALL_FORMAT_SPECIFIERS, *s)
				|| !ft_get_spec(&s, spec) || !ft_get_conversion(&s, spec)
				|| spec->n_chars > (size_t)INT32_MAX)
				return (-1);
			s++;
		}
		fmt = s;
	}
	return (0);
}

int	ft_get_conversion(const char **fmt, t_spec *spec)
{
	if (**fmt == 's')
		return (ft_convert_s(spec));
	if (**fmt == 'c')
		return (ft_convert_c(spec));
	if (**fmt == 'p')
		return (ft_convert_p(spec));
	if (**fmt == 'd' || **fmt == 'i')
		return (ft_convert_d(spec));
	if (**fmt == 'u')
		return (ft_convert_u(spec));
	if (**fmt == 'x')
		return (ft_convert_x_low(spec));
	if (**fmt == 'X')
		return (ft_convert_x_up(spec));
	else
		return (ft_convert_percent(spec));
}
