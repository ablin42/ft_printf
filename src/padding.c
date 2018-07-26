/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:23:42 by ablin             #+#    #+#             */
/*   Updated: 2018/07/08 01:23:53 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		blank_and_sign(t_arg *lst, uintmax_t size, int signe, int toprint)
{
	int		retour;

	retour = 0;
	if (is_there(lst->wflag, '+') || signe == -1 || is_there(lst->wflag, ' '))
		toprint--;
	if (is_there(lst->wflag, '+') && signe != 1 && is_flag_zero(lst->wflag)
		&& lst->flag != 'o' && lst->flag != 'O')
		ft_putchar('+');
	if (!is_there(lst->wflag, '-') && !is_flag_zero(lst->wflag))
		to_print(' ', toprint);
	if (is_there(lst->wflag, '+') && signe != -1 && !is_flag_zero(lst->wflag)
		&& lst->flag != 'o' && lst->flag != 'O')
		ft_putchar('+');
	else if (is_there(lst->wflag, ' ') && signe != -1)
		ft_putchar(' ');
	if (toprint > 0)
		retour += toprint;
	if (is_there(lst->wflag, ' ') || (is_there(lst->wflag, '+') && lst->flag != 'o'
		&& lst->flag != 'O') || signe == -1)
		retour++;
	return (retour);
}

int		precision_and_zero(t_arg *lst, uintmax_t size, int signe)
{
	int		toprint;

	toprint = atoi_wflag(lst->wflag) - size - htag(lst, signe, 0);
	if (size < atoi_precision(lst->wflag))
		toprint = atoi_wflag(lst->wflag) - atoi_precision(lst->wflag);
	if (is_there(lst->wflag, '+') || signe < 0 || is_there(lst->wflag, ' '))
		toprint--;
	htag(lst, signe, 1);
	if (signe < 0)
		ft_putchar('-');
	if (is_flag_zero(lst->wflag) && !is_there(lst->wflag, '-'))
		to_print_s(toprint, lst->wflag);
	if (is_there(lst->wflag, '.') && signe == 0 && atoi_precision(lst->wflag) == 0)
		return (htag(lst, signe, 0));
	toprint = atoi_precision(lst->wflag) - size;
	if (lst->flag == 'o' && is_there(lst->wflag, '#'))
		toprint = atoi_precision(lst->wflag) - size - htag(lst, signe, 0);
	to_print('0', toprint);
	if (toprint > 0 && is_there(lst->wflag, '.'))
		return (toprint);
	return (0);
}

void	minus_flag(t_arg *lst, int toprint)
{
	if (is_there(lst->wflag, '-'))
	{
		if (is_there(lst->wflag, '+') || is_there(lst->wflag, ' '))
			toprint--;
		to_print(' ', toprint);
	}
}

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
	if (is_there(lst->wflag, '.') && nb == 0 && atoi_precision(lst->wflag) == 0)
		r = 0;
	toprint = atoi_wflag(lst->wflag) - r;
	if (r < atoi_precision(lst->wflag))
		toprint = atoi_wflag(lst->wflag) - atoi_precision(lst->wflag);
	r += blank_and_sign(lst, divide_nb(nb, lst->base), signe, toprint);
	r += precision_and_zero(lst, divide_nb(nb, lst->base), signe);
	if (nb < 0)
		nb *= -1;
	if (!is_there(lst->wflag, '.') || (is_there(lst->wflag, '.') && signe != 0))
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
	if (is_there(lst->wflag, '.') && nb == 0 && atoi_precision(lst->wflag) == 0)
		r = 0;
	toprint = atoi_wflag(lst->wflag) - r;
	if (r < atoi_precision(lst->wflag))
		toprint = atoi_wflag(lst->wflag) - atoi_precision(lst->wflag);
	r += blank_and_sign(lst, divide_unb(nb, lst->base), signe, toprint);
	r += precision_and_zero(lst, divide_unb(nb, lst->base), signe);
	if (lst->flag == 'X' && (!is_there(lst->wflag, '.') ||
	(is_there(lst->wflag, '.') && signe != 0)))
		ft_putstr(ft_strtoupper(ft_itoa_base_u(nb, lst->base)));
	else if (!is_there(lst->wflag, '.') ||
	(is_there(lst->wflag, '.') && signe != 0))
		ft_putstr(ft_itoa_base_u(nb, lst->base));
	minus_flag(lst, toprint);
	return (r);
}
