/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 23:27:50 by ablin             #+#    #+#             */
/*   Updated: 2018/06/02 23:27:56 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		divide_nb(intmax_t nb, int divider)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= divider;
		i++;
	}
	return (i);
}

int		divide_unb(uintmax_t nb, int base)
{
	int		ret;
	ret = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= base;
		ret++;
	}
	return (ret);
}

int		to_print(char c, int toprint)
{
	while (toprint > 0)
	{
		ft_putchar(c);
		toprint--;
	}
	return (toprint);
}

void		to_print_s(int toprint, char *wflag)
{
	while (toprint > 0)
	{
		if (is_flag_zero(wflag) && !is_there(wflag, '.'))
			ft_putchar('0');
		else
			ft_putchar(' ');
		toprint--;
	}
}

int		wchar_len(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}
