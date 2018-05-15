#include <stdarg.h>
#include "../libft/libft.h"
#include "../includes/printf.h"
#include "fill_list.c"

int		count_flags(const char * restrict format)
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

int		ft_printf(const char * restrict format, ...)
{
	char	*ret;
	t_arg	*lst;
	va_list ap;

	ret = 0;
	va_start(ap, format);
	lst_type_arg(&lst, format);
	lst = cycle_arg(lst, ap);
	test(lst);
	test2(lst);
	return (0);
}
