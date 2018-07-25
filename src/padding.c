/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:23:42 by ablin             #+#    #+#             */
/*   Updated: 2018/06/02 21:31:28 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		blank_and_sign(char *wflag, char flag, long long int nb, int toprint)
{
	int		retour;

	retour = 0;
	if (is_there(wflag, '+') || nb < 0 || is_there(wflag, ' '))
		toprint--;
	if (is_there(wflag, '+') && nb >= 0 && is_flag_zero(wflag)
		&& flag != 'o' && flag != 'O')
		ft_putchar('+');
	if (!is_there(wflag, '-') && !is_flag_zero(wflag))
		to_print(' ', toprint);
	if (is_there(wflag, '+') && nb >= 0 && !is_flag_zero(wflag)
		&& flag != 'o' && flag != 'O')
		ft_putchar('+');
	else if (is_there(wflag, ' ') && nb >= 0)
		ft_putchar(' ');
	if (toprint > 0)
		retour += toprint;
	if (is_there(wflag, ' ') || (is_there(wflag, '+') && flag != 'o' 
		&& flag != 'O') || nb < 0)
		retour++;
	return (retour);
}

int		precision_and_zero(char *wflag, long long int nb, int base, char flag)
{
	int		toprint;

	toprint = atoi_wflag(wflag) - divide_nb(nb, base) - hashtag_handler(wflag, flag, nb, 0);
	if (divide_nb(nb, 10) < atoi_precision(wflag))
		toprint = atoi_wflag(wflag) - atoi_precision(wflag);
	if (is_there(wflag, '+') || nb < 0 || is_there(wflag, ' '))
		toprint--;
	hashtag_handler(wflag, flag, nb, 1);
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (is_flag_zero(wflag))
		to_print('0', toprint);
	if (is_there(wflag, '.') && nb == 0 && atoi_precision(wflag) == 0)
		return (hashtag_handler(wflag, flag, nb, 0));
	toprint = atoi_precision(wflag) - divide_nb(nb, base);
	if (flag == 'o' && is_there(wflag, '#'))
		toprint = atoi_precision(wflag) - divide_nb(nb, base) - hashtag_handler(wflag, flag, nb, 0);
	to_print('0', toprint);
	if (flag == 'X')
		ft_putstr(ft_strtoupper(ft_itoa_base_long(nb, base)));
	else
		ft_putstr(ft_itoa_base_long(nb, base));
	if (toprint > 0 && is_there(wflag, '.'))
		return (toprint);
	return (0);
}

int		padding(char *wflag, long long int nb, int base, char flag)
{
	int		retour;
	int		toprint;
	
	retour = divide_nb(nb, base) + hashtag_handler(wflag, flag, nb, 0);
	if (is_there(wflag, '.') && nb == 0 && atoi_precision(wflag) == 0)
		retour = 0;
	toprint = atoi_wflag(wflag) - retour;
	if (retour < atoi_precision(wflag))
		toprint = atoi_wflag(wflag) - atoi_precision(wflag);
	retour += blank_and_sign(wflag, flag, nb, toprint);
	retour += precision_and_zero(wflag, nb, base, flag);
	if (is_there(wflag, '-'))
	{
		if (is_there(wflag, '+') || nb < 0 || is_there(wflag, ' '))
			toprint--;
		to_print(' ', toprint);
	}
	return (retour);
}

intmax_t	handle_length(t_arg *lst, va_list ap)
{
	intmax_t	nb;
/*
	if (param.modifier == L)
		nb = va_arg(ap, long);
	else if (param.modifier == LL)
		nb = va_arg(ap, long long);
	else if (param.modifier == J)
		nb = va_arg(ap, intmax_t);
	else if (param.modifier == Z)
		nb = va_arg(ap, ssize_t);*/

	if (lst->flag == 'd' || lst->flag == 'i')
		nb = va_arg(ap, int);
	if (lst->flag == 'u' || lst->flag == 'x' || lst->flag == 'X' || lst->flag == 'o')
		nb = va_arg(ap, unsigned int);
	if (lst->flag == 'p')
		nb = va_arg(ap, unsigned long);
	if (lst->flag == 'D')
		nb = va_arg(ap, long int);
	if (lst->flag == 'U')
		nb = va_arg(ap, unsigned long long);
	if (lst->flag == 'O')
		nb = va_arg(ap, unsigned long);
	if (lst->mod == 1)
		nb = (char)nb;
	if (lst->mod == 2)
		nb = (short)nb;
	return (nb);
}
uintmax_t	handle_ulength(t_arg *lst, va_list ap)
{
	uintmax_t	nb;
/*
	if (param.modifier == L)
		nb = va_arg(ap, unsigned long);
	else if (param.modifier == LL)
		nb = va_arg(ap, unsigned long long);
	else if (param.modifier == J)
		nb = va_arg(ap, uintmax_t);
	else if (param.modifier == Z)
		nb = va_arg(ap, size_t);*/

	if (lst->flag == 'u' || lst->flag == 'x' || lst->flag == 'X' || lst->flag == 'o')
		nb = va_arg(ap, unsigned int);
	if (lst->flag == 'p')
		nb = va_arg(ap, unsigned long);
	if (lst->flag == 'D')
		nb = va_arg(ap, long int);
	if (lst->flag == 'U')
		nb = va_arg(ap, unsigned long long);
	if (lst->flag == 'O')
		nb = va_arg(ap, unsigned long);
	if (lst->mod == 1)
		nb = (char)nb;
	if (lst->mod == 2)
		nb = (short)nb;
	return (nb);
}

int		int_handler(t_arg *lst, va_list ap)
{
	int		retour;
	int		toprint;
	intmax_t	nb;
	int		base;
	
	nb = handle_length(lst, ap);
	retour = divide_nb(nb, lst->base) + hashtag_handler(lst->wflag, lst->flag, nb, 0);//10->base
	if (is_there(lst->wflag, '.') && nb == 0 && atoi_precision(lst->wflag) == 0)
		retour = 0;
	toprint = atoi_wflag(lst->wflag) - retour;
	if (retour < atoi_precision(lst->wflag))
		toprint = atoi_wflag(lst->wflag) - atoi_precision(lst->wflag);
	retour += blank_and_sign(lst->wflag, lst->flag, nb, toprint);
	retour += precision_and_zero(lst->wflag, nb, lst->base, lst->flag);//10->base
	if (is_there(lst->wflag, '-'))
	{
		if (is_there(lst->wflag, '+') || nb < 0 || is_there(lst->wflag, ' '))
			toprint--;
		to_print(' ', toprint);
	}
	return (retour);
}

int		hex_handler(t_arg *lst, va_list ap)
{
	int		retour;
	int		toprint;
	uintmax_t	nb;
	int		base;
	
	nb = handle_ulength(lst, ap);
	retour = divide_nb(nb, lst->base) + hashtag_handler(lst->wflag, lst->flag, nb, 0);//10->base
	if (is_there(lst->wflag, '.') && nb == 0 && atoi_precision(lst->wflag) == 0)
		retour = 0;
	toprint = atoi_wflag(lst->wflag) - retour;
	if (retour < atoi_precision(lst->wflag))
		toprint = atoi_wflag(lst->wflag) - atoi_precision(lst->wflag);
	retour += blank_and_sign(lst->wflag, lst->flag, nb, toprint);
	retour += precision_and_zero(lst->wflag, nb, lst->base, lst->flag);//10->base
	if (is_there(lst->wflag, '-'))
	{
		if (is_there(lst->wflag, '+') || is_there(lst->wflag, ' '))
			toprint--;
		to_print(' ', toprint);
	}
	return (retour);
}
