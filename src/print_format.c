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
#include <stdio.h>

void	ft_putfloat(float n)
{
	n += 1.000002;
	printf("%f", n);//float addition is EXACTLY precise
}

void	ft_putlong(long long n)
{
	if (n == -9223372036854775807)
	{
		ft_putchar('-');
		ft_putlong(922337203685477580);
		ft_putchar('7');
	}
	if (n < 0 && n != -9223372036854775807)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putlong(n / 10);
		ft_putlong(n % 10);
	}
	else if (n != -9223372036854775807 && n <= 9)
	{
		ft_putchar(n + '0');
	}
}

void	ft_putulong(unsigned long long n)
{
	if (n > 9)
	{
		ft_putulong(n / 10);
		ft_putulong(n % 10);
	}
	else if (n <= 9)
	{
		ft_putchar(n + '0');
	}
}
