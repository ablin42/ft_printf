/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:24:08 by ablin             #+#    #+#             */
/*   Updated: 2018/06/02 21:20:31 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include "../includes/printf.h"
#include "fill_list.c"

int		count_flags(const char *restrict format)
{
	int		nbflags;

	nbflags = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			nbflags++;
		format++;
	}
	return (nbflags);
}

int		ft_printf(const char *restrict format, ...)
{
	t_arg	*lst;
	int		retour;
	va_list ap;

	retour = 0;
	va_start(ap, format);
	lst_type_arg(&lst, format);
	lst = cycle_arg(lst, ap);
//	test(lst, &retour);
	test2(lst, &retour);
	return (retour);
}
