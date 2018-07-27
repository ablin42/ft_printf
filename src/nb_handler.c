#include "../includes/printf.h"

int		int_handler(t_arg *lst, va_list ap)
{
	int		r;
	int		toprint;
	intmax_t	nb;
	int			signe;

	signe = 1;
	nb = handle_length(lst, ap);
	if (nb == 0)
		signe = 0;
	if (nb < 0)
		signe = -1;
	r = divide_nb(nb, lst->base) + htag(lst, signe, 0);
	if (is_there(lst->wflag, '.') && nb == 0 && get_preci(lst->wflag) == 0)
		r = 0;
	toprint = get_pad(lst->wflag) - r;
	if (r < get_preci(lst->wflag))
		toprint = get_pad(lst->wflag) - get_preci(lst->wflag);
	r += blank_and_sign(lst, divide_nb(nb, lst->base), signe, toprint);
	r += precision_and_zero(lst, divide_nb(nb, lst->base), signe);
	if (nb < 0)
		nb *= -1;
	if (is_there(lst->wflag, '.') && get_pad(lst->wflag) == 0 && signe == 0)
		return (r);
	ft_putstr(ft_itoa_base_u(nb, lst->base));
	minus_flag(lst, toprint);
	return (r);
}

int		hex_handler(t_arg *lst, va_list ap)
{
	int		r;
	int		toprint;
	uintmax_t	nb;
	int			signe;

	signe = 1;
	nb = handle_ulength(lst, ap);
	if (nb == 0)
		signe = 0;
	r = divide_unb(nb, lst->base) + htag(lst, signe, 0);
	if (is_there(lst->wflag, '.') && nb == 0 && get_preci(lst->wflag) == 0)
		r = 0;
	toprint = get_pad(lst->wflag) - r;
	if (r < get_preci(lst->wflag))
		toprint = get_pad(lst->wflag) - get_preci(lst->wflag);
	r += blank_and_sign(lst, divide_unb(nb, lst->base), signe, toprint);
	r += precision_and_zero(lst, divide_unb(nb, lst->base), signe);
	if (lst->flag == 'X' && (!is_there(lst->wflag, '.') ||
	(is_there(lst->wflag, '.') && signe != 0)))
		ft_putstr(ft_strtoupper(ft_itoa_base_u(nb, lst->base)));
	else if (!is_there(lst->wflag, '.') || (is_there(lst->wflag, '.')
	&& (signe != 0 || (lst->flag == 'p' && get_preci(lst->wflag) != 0))))
		ft_putstr(ft_itoa_base_u(nb, lst->base));
	minus_flag(lst, toprint);
	return (r);
}
