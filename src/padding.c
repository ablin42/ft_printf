/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:23:42 by ablin             #+#    #+#             */
/*   Updated: 2018/05/17 22:37:00 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_nbpadding(int toprint, char *wflag, int nb)
{
	int		nbprint;

	nbprint = nb;
	if (is_flag_zero(wflag) && is_there(wflag, '+') && nb >= 0)
		ft_putchar('+');
	else if (toprint > 1 && nb < 0 && is_flag_zero(wflag))
	{
		ft_putchar('-');
		nb *= -1;
	}
	while (toprint > 1)
	{
		if (is_flag_zero(wflag))
			ft_putchar('0');
		else
			ft_putchar(' ');
		toprint--;
	}
	if (!is_flag_zero(wflag) && is_there(wflag, '+') && nbprint >= 0)
		ft_putchar('+');
	ft_putnbr(nb);
}

void		ft_nbpaddingdata(char *wflag, int nb)//int nb for now
{
	int		divider;
	int		toprint;
	int		nbprint;

	divider = 0;
	nbprint = nb;
	while (nb / 10)
	{
		nb /= 10;
		divider++;
	}
	if (is_there(wflag, '+') || nbprint < 0)
		divider++;
	toprint = ft_atoi_wflag(wflag) - divider;
	ft_nbpadding(toprint, wflag, nbprint);
}
/*
void		ft_nbpadding(char *wflag, int nb)//int nb for now
{
	int		divider;
	int		toprint;
	int		nbprint;

	divider = 0;
	nbprint = nb;
	while (nb / 10)
	{
		nb /= 10;
		divider++;
	}
	if (is_there(wflag, '+') || nbprint < 0)
		divider++;
	toprint = ft_atoi_wflag(wflag) - divider;

	if (is_flag_zero(wflag) && is_there(wflag, '+') && nbprint > 0)
		ft_putchar('+');
	if (nbprint < 0 && toprint > 2)
	{
		ft_putchar('-');
		nbprint *= -1;
	}
	while (toprint > 1)
	{
		if (is_flag_zero(wflag))
			ft_putchar('0');
		else
			ft_putchar(' ');
		toprint--;
	}
//	if (!is_flag_zero(wflag))
//		ft_putchar('+');
	ft_putnbr(nbprint);
}*/

void		ft_leftjustify(char *wflag, int nb)//int nb for now
{
	int		divider;
	int		toprint;
	int		nbprint;

	divider = 0;
	nbprint = nb;
	while (nb / 10)
	{
		nb /= 10;
		divider++;
	}
	if (is_there(wflag, '+'))
		divider++;
	if (is_there(wflag, '+') && nb >= 0)//something in print first
		ft_putchar('+');
	if (is_there(wflag, '-'))
		ft_putnbr(nbprint);
	toprint = ft_atoi_wflag(wflag) - divider;
	if (ft_atoi_wflag(wflag) < 0)
	toprint *= -1;
	while (toprint > 1)
	{
		ft_putchar(' ');
		toprint--;
	}
}
