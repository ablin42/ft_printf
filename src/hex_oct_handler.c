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

int		O_handler(char *wflag, unsigned long nb, char flag)
{
	int		retour;

	retour = 0;
	if (flag == 'o' || flag == 'O')
	{
		if (is_there(wflag, '#') && nb != 0)
		{
			retour += 1;
			ft_putchar('0');
		}
		ft_putstr(ft_itoa_base_long(nb, 8));
		retour += ft_strlen(ft_itoa_base_long(nb, 8));
	}
	return (retour);
}

int		octal_handler(char *wflag, unsigned int nb, char flag)
{
	int		retour;

	retour = 0;
	if (flag == 'o' || flag == 'O')
	{
		if (is_there(wflag, '#') && nb != 0)
		{
			retour += 1;
			ft_putchar('0');
		}
		ft_putstr(ft_itoa_base(nb, 8));
		retour += ft_strlen(ft_itoa_base(nb, 8));
	}
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
			if (is_there(wflag, '#') && nb != 0)
				ft_putstr("0x");
			ft_putstr(ft_itoa_base(nb, 16));
		}
		if (flag == 'X')
		{
			if (is_there(wflag, '#') && nb != 0)
				ft_putstr("0X");
			ft_putstr(ft_itoa_base_up(nb, 16));
		}
		retour += ft_strlen(ft_itoa_base(nb, 16));
		if (is_there(wflag, '#') && nb != 0)
			retour += 2;
	}
	if (flag == 'o' || flag == 'O')
		retour += octal_handler(wflag, nb, flag);
	return (retour);
}
