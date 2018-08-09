/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:40:00 by ablin             #+#    #+#             */
/*   Updated: 2018/08/09 02:53:08 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** this function divide a nb by its divider and return the amount of time it
** can be divided by (intmax_t nb)
*/

int		divide_nb(intmax_t nb, int divider, char *wflag)
{
	int		i;

	i = 0;
	if (nb == 0)
	{
		if (is_there(wflag, '.') && get_preci(wflag) == 0)
			return (0);
		return (1);
	}
	while (nb != 0)
	{
		nb /= divider;
		i++;
	}
	return (i);
}

/*
** this function divide a nb by its divider and return the amount of time it
** can be divided by (uintmax_t nb)
*/

int		divide_unb(uintmax_t nb, int base, char *wflag)
{
	int		ret;

	ret = 0;
	if (nb == 0)
	{
		if (is_there(wflag, '.') && get_preci(wflag) == 0)
			return (0);
		return (1);
	}
	while (nb != 0)
	{
		nb /= base;
		ret++;
	}
	return (ret);
}

/*
** this function prints the char c times toprint
*/

int		to_print(char c, int toprint)
{
	while (toprint > 0)
	{
		ft_putchar(c);
		toprint--;
	}
	return (toprint);
}

/*
** this function prints '0' or ' ' times toprint depending on the flags
*/

void	to_print_s(int toprint, char *wflag)
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

/*
** this function returns the size of a wchar_t
*/

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
