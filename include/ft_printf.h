/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:27:30 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/12 13:27:31 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

# define ALL_FORMAT_SPECIFIERS	"cspdiuxX%-.# +0123456789"
# define LEFT					1
# define ZERO					2
# define MINFW					4
# define PRC					8
# define SPACE					16
# define PLUS					32
# define ALT					64

typedef struct s_spec
{
	va_list			sap;
	size_t			n_chars;
	unsigned char	flags;
	int				minfw;
	int				prc;
	char			*p;
	char			*buffer;
}	t_spec;

int		ft_printf(const char *fmt, ...);
int		ft_parse_format(const char *fmt, t_spec *spec);
int		ft_get_spec(const char **fmt, t_spec *spec);
int		ft_get_conversion(const char **fmt, t_spec *spec);
int		ft_convert_s(t_spec *spec);
int		ft_convert_c(t_spec *spec);
int		ft_convert_p(t_spec *spec);
int		ft_convert_d(t_spec *spec);
int		ft_convert_u(t_spec *spec);
int		ft_convert_x_low(t_spec *spec);
int		ft_convert_x_up(t_spec *spec);
int		ft_convert_percent(t_spec *spec);

char	*ft_get_padded_string(t_spec *spec, size_t n_chars, int c);
int		ft_get_precision_fill(t_spec *spec, long d);
int		ft_get_zero_or_blank_fill(t_spec *spec, long d);
int		ft_prepend_sign_or_blank(t_spec *spec);

#endif
