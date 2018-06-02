/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:15:03 by ablin             #+#    #+#             */
/*   Updated: 2018/06/02 21:15:21 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		hashtag_handler(char *wflag, int nb)
{
	int		retour;

	retour = 0;
	if (nb > 0)
	{
		if (is_there(wflag, 'o'))
			ft_putchar('0');
		if (is_there(wflag, 'x'))
			ft_putstr("0x");
		if (is_there(wflag, 'X'))
			ft_putstr("0X");
	}
	return (retour);
}
