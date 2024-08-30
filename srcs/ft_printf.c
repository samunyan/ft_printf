/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:26:58 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/12 13:26:59 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		i;
	t_spec	spec;

	ft_bzero(&spec, sizeof(spec));
	va_start(spec.sap, fmt);
	i = ft_parse_format(fmt, &spec);
	va_end(spec.sap);
	if (i != -1)
	{
		i = spec.n_chars;
		if (write(STDOUT_FILENO, spec.buffer, i) == -1)
			i = -1;
	}
	free(spec.buffer);
	return (i);
}
