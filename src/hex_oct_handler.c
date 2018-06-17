/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_oct_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:15:03 by ablin             #+#    #+#             */
/*   Updated: 2018/06/02 21:15:21 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		print_addr(char *wflag, unsigned long p)
{
	int		ret;
	int		toprint;

	ret = 2;
	toprint = atoi_wflag(wflag) - ft_strlen(ft_itoa_base_long(p, 16)) - ret;
	if (toprint > 0)
		ret += toprint;
	if (is_flag_zero(wflag) || (toprint > 0 && is_there(wflag, '-'))
		|| is_there(wflag, '-'))
		ft_putstr("0x");
	if (is_there(wflag, '-'))
		ft_putstr(ft_itoa_base_long(p, 16));
	if (is_flag_zero(wflag))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_flag_zero(wflag) && !is_there(wflag, '-'))
		ft_putstr("0x");
	if (!is_there(wflag, '-'))
		ft_putstr(ft_itoa_base_long(p, 16));
	ret += ft_strlen(ft_itoa_base_long(p, 16));
	return (ret);
}

int		O_handler(char *wflag, unsigned long nb, char flag)
{
	int		retour;

	retour = 0;
	if (is_there(wflag, '#') && nb != 0)
	{
		retour += 1;
		ft_putchar('0');
	}
	ft_putstr(ft_itoa_base_long(nb, 8));
	retour += ft_strlen(ft_itoa_base_long(nb, 8));
	
	return (retour);
}

int		octal_handler(char *wflag, unsigned int nb, char flag)
{
	int		retour;
	int		toprint;
	int		totalprinted;

	totalprinted = 0;
	if (nb == 0 && atoi_precision(wflag) == 0)
		return (0);
	retour = ft_strlen(ft_itoa_base(nb, 8));
	toprint = atoi_wflag(wflag) - retour;
	if (retour < atoi_precision(wflag))
		toprint = atoi_wflag(wflag) - atoi_precision(wflag);
	to_print(' ', toprint);
	if (toprint > 0)
		totalprinted += toprint;
	if (is_there(wflag, '#') && nb != 0)
	{
		retour += 1;
		ft_putchar('0');
	}
	toprint = atoi_precision(wflag) - retour;
	if (toprint > 0)
		totalprinted += toprint;
	to_print('0', toprint);
	ft_putstr(ft_itoa_base(nb, 8));
	retour += totalprinted;
	return (retour);
}

int		hex_oct_handler(char *wflag, unsigned int nb, char flag)
{
	int retour;

	retour = 0;
	if (flag == 'x' || flag == 'X')
	{
		if (flag == 'x')
		{
			retour += hex_padding(wflag, ft_itoa_base(nb, 16), "0x");
		//	if (is_there(wflag, '#') && nb != 0)
		//		ft_putstr("0x");
		//	ft_putstr(ft_itoa_base(nb, 16));
		}
		if (flag == 'X')
		{
			retour += hex_padding(wflag, ft_itoa_base_up(nb, 16), "0X");
		//	if (is_there(wflag, '#') && nb != 0)
		//		ft_putstr("0X");
		//	ft_putstr(ft_itoa_base_up(nb, 16));
		}
		retour += ft_strlen(ft_itoa_base(nb, 16));
	}
	if (flag == 'o' || flag == 'O')
		retour += octal_handler(wflag, nb, flag);
	return (retour);
}
