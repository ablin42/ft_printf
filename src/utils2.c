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

int		ft_iputstr(char *s)
{
	int i;

	i = 0;
	if (s == NULL || s == 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i] != '\0')
		i++;
	write(1, s, i);
	return (i);
}

int		divide_nb(long long nb, int divider)
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

int		divide_ull(unsigned long long n, int base)
{
	int		ret;
	ret = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
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
