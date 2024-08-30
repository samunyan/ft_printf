/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:19:40 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/12 20:19:42 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_flags(const char **fmt, t_spec *spec)
{
	spec->flags = 0;
	while (**fmt && ft_strchr("-0# +", **fmt))
	{
		if (**fmt == '-')
			spec->flags |= LEFT;
		else if (**fmt == '0')
			spec->flags |= ZERO;
		else if (**fmt == '#')
			spec->flags |= ALT;
		else if (**fmt == ' ')
			spec->flags |= SPACE;
		else if (**fmt == '+')
			spec->flags |= PLUS;
		(*fmt)++;
	}
}

static void	ft_get_minfieldwidth(const char **fmt, t_spec *spec)
{
	spec->minfw = 0;
	if (ft_isdigit(**fmt))
	{
		spec->flags |= MINFW;
		spec->minfw = ft_atoi(*fmt);
		if (!ft_atoi_is_valid(spec->minfw, *fmt))
			spec->minfw = -1;
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
}

static void	ft_get_precision(const char **fmt, t_spec *spec)
{
	spec->prc = 0;
	if (**fmt == '.')
	{
		spec->flags |= PRC;
		(*fmt)++;
		if (ft_isdigit(**fmt))
		{
			spec->prc = ft_atoi(*fmt);
			if (!ft_atoi_is_valid(spec->prc, *fmt))
				spec->prc = -1;
			while (ft_isdigit(**fmt))
				(*fmt)++;
		}
	}
}

int	ft_get_spec(const char **fmt, t_spec *spec)
{
	ft_get_flags(fmt, spec);
	ft_get_minfieldwidth(fmt, spec);
	ft_get_precision(fmt, spec);
	if (spec->minfw == INT32_MAX
		|| ((spec->flags & MINFW) && spec->minfw == -1))
		return (0);
	if (ft_strchr("diuxX", **fmt))
	{
		if (spec->prc == INT32_MAX || ((spec->flags & PRC) && spec->prc == -1))
			return (0);
		if ((spec->flags & ZERO) && (spec->flags & PRC))
			spec->flags &= ~ZERO;
		if ((spec->flags & ZERO) && (spec->flags & LEFT))
			spec->flags &= ~ZERO;
	}
	return (1);
}
