/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:23:42 by ablin             #+#    #+#             */
/*   Updated: 2018/05/17 22:37:00 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_strpadding(char *wflag, char *str)
{
	int		toprint;

	toprint = ft_atoi_wflag(wflag) - ft_strlen(str) + 1;//attention quand strlen renvoi 0
	if (is_there(wflag, '-'))
		ft_putstr(str);
	while (toprint > 1)
	{
		ft_putchar(' ');
		toprint--;
	}
	if (!is_there(wflag, '-'))
		ft_putstr(str);
}
