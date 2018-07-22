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
	if (is_flag_zero(wflag) && !is_there(wflag, '-'))
		to_print_s(toprint, wflag);
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
