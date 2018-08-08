#include "../includes/printf.h"

/*
 * this function handle and print the width and call to the function that handle
 * the other flags for signed nb
 * this includes the conversion specifiers: (dD)
*/

void	int_handler(t_arg *lst, va_list ap, int *r)
{
	int		toprint;
	int		total;
	intmax_t	nb;
	int			signe;

	signe = 1;
	nb = handle_length(lst, ap);
	if (nb == 0)
		signe = 0;
	if (nb < 0)
		signe = -1;
	total = divide_nb(nb, lst->base, lst->wflag) + htag(lst, signe, 0);
	if (is_there(lst->wflag, '.') && nb == 0 && get_preci(lst->wflag) == 0)
		total = 0;
	*r += total;
	toprint = get_pad(lst->wflag) - total;
	if (total < get_preci(lst->wflag))
		toprint = get_pad(lst->wflag) - get_preci(lst->wflag);
	*r += blank_and_sign(lst, divide_nb(nb, lst->base, lst->wflag), signe, toprint);
	*r += precision_and_zero(lst, divide_nb(nb, lst->base, lst->wflag), signe);
	if (nb < 0)
		nb *= -1;
	if (!is_there(lst->wflag, '.') || get_preci(lst->wflag) != 0 || nb != 0)
		pf_itoa_base(nb, lst->base, lst->flag);
	minus_flag(lst, toprint, signe);
}

/*
 * this function handle and print the width and call to the function that handle
 * the other flags for unsigned nb
 * this includes the conversion specifiers: (xXoOuUp)
*/

void	hex_handler(t_arg *lst, va_list ap, int *r)
{
	int		total;
	int		toprint;
	uintmax_t	nb;
	int			signe;

	signe = 1;
	nb = handle_ulength(lst, ap);
	if (nb == 0)
		signe = 0;
	total = divide_unb(nb, lst->base, lst->wflag) + htag(lst, signe, 0);
	if (is_there(lst->wflag, '.') && nb == 0 && get_preci(lst->wflag) == 0)
		total = 0;
	*r += total;
	toprint = get_pad(lst->wflag) - total;
	if (total - htag(lst, signe, 0) < get_preci(lst->wflag))
		toprint = get_pad(lst->wflag) - get_preci(lst->wflag) - htag(lst, signe, 0);
	*r += blank_and_sign(lst, divide_unb(nb, lst->base, lst->wflag), signe, toprint);
	*r += precision_and_zero(lst, divide_unb(nb, lst->base, lst->wflag), signe);
	if (lst->flag == 'X' && (!is_there(lst->wflag, '.') ||
	(is_there(lst->wflag, '.') && signe != 0)))
		pf_itoa_base(nb, lst->base, lst->flag);
	else if (!is_there(lst->wflag, '.') || (is_there(lst->wflag, '.')
	&& (signe != 0 || ((lst->flag == 'p' || lst->flag == 'U' || lst->flag == 'O') && get_preci(lst->wflag) != 0))))
		pf_itoa_base(nb, lst->base, lst->flag);
	*r += minus_flag(lst, toprint, signe);
}
