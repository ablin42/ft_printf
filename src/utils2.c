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

int		divide_nb(int nb, int divider)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb % divider)
	{
		nb /= divider;
		i++;
	}
	return (i);
}

int		divide_ll(long long n)
{
	int		ret;
	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		ret++;
	while (n != 0)
	{
		n /= 10;
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
