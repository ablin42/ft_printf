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

int		blank_and_sign(char *wflag, long long nb, int toprint)
{
	int		retour;

	retour = 0;
	if (is_there(wflag, '+') || nb < 0 || is_there(wflag, ' '))
		toprint--;
	if (is_there(wflag, '+') && nb >= 0 && is_flag_zero(wflag))
		ft_putchar('+');
	if (!is_there(wflag, '-') && !is_flag_zero(wflag))
		to_print(' ', toprint);
	if (is_there(wflag, '+') && nb >= 0 && !is_flag_zero(wflag))
		ft_putchar('+');
	else if (is_there(wflag, ' ') && nb >= 0)
		ft_putchar(' ');
	if (toprint > 0)
		retour += toprint;
	if (is_there(wflag, ' ') || is_there(wflag, '+') || nb < 0)
		retour++;
	return (retour);
}

int		precision_and_zero(char *wflag, long long nb, int toprint, int base)
{
	int		retour;

	retour = divide_nb(nb, base);
	if (is_there(wflag, '+') || nb < 0 || is_there(wflag, ' '))
		toprint--;
	hashtag_handler(wflag, nb, 1);
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (is_flag_zero(wflag))
		to_print('0', toprint);
	if (is_there(wflag, '.') && nb == 0 && atoi_precision(wflag) == 0)
		return (0);
	toprint = atoi_precision(wflag) - retour;
	to_print('0', toprint);
	if (is_there(wflag, 'X'))
		ft_putstr(ft_strtoupper(ft_itoa_base_long(nb, base)));
	else
		ft_putstr(ft_itoa_base_long(nb, base));
	if (toprint > 0 && is_there(wflag, '.'))
		return (toprint);
	return (0);
}

int		padding(char *wflag, long long nb, int base)
{
	int retour;
	int toprint;
	
	retour = divide_nb(nb, base) + hashtag_handler(wflag, nb, 0);
	if (is_there(wflag, '.') && nb == 0 && atoi_precision(wflag) == 0)
		retour = 0;
	toprint = atoi_wflag(wflag) - retour;
	if (retour < atoi_precision(wflag))
		toprint = atoi_wflag(wflag) - atoi_precision(wflag);
	retour += blank_and_sign(wflag, nb, toprint);
	retour += precision_and_zero(wflag, nb, toprint, base);
	if (is_there(wflag, '-'))
	{
		if (is_there(wflag, '+') || nb < 0 || is_there(wflag, ' '))
			toprint--;
		to_print(' ', toprint);
	}
	return (retour);
}
