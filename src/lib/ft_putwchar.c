/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:49:38 by ablin             #+#    #+#             */
/*   Updated: 2018/08/19 03:30:34 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libfunc.h"

int		ft_putwchar(wchar_t c)
{
	if (c <= 0x7F && MB_CUR_MAX >= 1)//
		ft_putchar(c);
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)//
	{
		ft_putchar((c >> 6) | 0xC0);
		ft_putchar((c & 0x3F) | 0x80);
		return (2);
	}
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)//
	{
		ft_putchar((c >> 12) | 0xE0);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
		return (3);
	}
	else if (c <= 0x10FFFF && MB_CUR_MAX >= 4)//
	{
		ft_putchar((c >> 18) | 0xF0);
		ft_putchar(((c >> 12) & 0x3F) | 0x80);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
		return (4);
	}
	return (1);
}
