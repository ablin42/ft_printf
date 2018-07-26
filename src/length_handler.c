#include "../includes/printf.h"

intmax_t	handle_length(t_arg *lst, va_list ap)
{
	intmax_t	nb;
	
	if (lst->mod == 3)
		nb = va_arg(ap, long);
	else if (lst->mod == 4 || lst->flag == 'D')
		nb = va_arg(ap, long long);
	else if (lst->mod == 5)
		nb = va_arg(ap, intmax_t);
	else if (lst->mod == 6)
		nb = va_arg(ap, size_t);
	else
		nb = va_arg(ap, int);
	if (lst->mod == 1)
		nb = (char)nb;
	if (lst->mod == 2)
		nb = (short)nb;
	if ((lst->mod == 1 || lst->mod == 2) && lst->flag == 'D')
		nb = (unsigned short)nb;
	return (nb);
}

uintmax_t	handle_ulength(t_arg *lst, va_list ap)
{
	uintmax_t	nb;
	
	if (lst->mod == 3 || lst->flag == 'U' || lst->flag == 'O'
		|| lst->flag == 'p')
		nb = va_arg(ap, unsigned long);
	else if (lst->mod == 4)
		nb = va_arg(ap, unsigned long long);
	else if (lst->mod == 5)
		nb = va_arg(ap, uintmax_t);
	else if (lst->mod == 6)
		nb = va_arg(ap, ssize_t);
	else
		nb = va_arg(ap, unsigned int);
	if (lst->mod == 1 && lst->flag != 'U' && lst->flag != 'O')
		nb = (unsigned char)nb;
	if (lst->mod == 2 && lst->flag != 'U' && lst->flag != 'O')
		nb = (unsigned short)nb;
	return (nb);
}
