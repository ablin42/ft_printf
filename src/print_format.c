/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:23:42 by ablin             #+#    #+#             */
/*   Updated: 2018/05/17 22:37:00 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_putlonglong(long long n)
{
	int		ret;

	ret = divide_ll(n);
	if (n == LONG_MIN)
	{
		ft_putchar('-');
		ft_putlonglong(922337203685477580);
		ft_putchar('8');
	}
	if (n < 0 && n != LONG_MIN)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putlonglong(n / 10);
		ft_putlonglong(n % 10);
	}
	else if (n != LONG_MIN && n <= 9)
	{
		ft_putchar(n + '0');
	}
	return (ret);
}

int		ft_putulong(unsigned long long n)
{
	int ret;

	ret = 0;
	if (n > 9)
	{
		ft_putulong(n / 10);
		ft_putulong(n % 10);
	}
	else if (n <= 9)
	{
		ft_putchar(n + '0');
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}
