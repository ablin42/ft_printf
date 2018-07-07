/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:23:42 by ablin             #+#    #+#             */
/*   Updated: 2018/07/08 01:31:01 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		hashtag_handler(char *wflag, char flag, long long int nb, int mode)
{
	if (flag == 'p')
	{
		if (mode == 1)
			ft_putstr("0x");
		return (2);
	}
	if (is_there(wflag, '#'))
	{
		if ((flag == 'o' || flag == 'O') && (nb != 0 || (nb == 0 &&
			is_there(wflag, '.') && atoi_precision(wflag) == 0)))
		{
			if (mode == 1)
				ft_putchar('0');
			return (1);
		}
		else if (flag == 'x' && nb != 0)
		{
			if (mode == 1)
				ft_putstr("0x");
			return (2);
		}
		else if (flag == 'X' && nb != 0)
		{
			if (mode == 1)
				ft_putstr("0X");
			return (2);
		}
	}
	return (0);
}

int		str_handler(char *wflag, char *str)
{
	int		toprint;
	int		retour;
	char	*dup;

	if (str != NULL && str != 0)
		dup = ft_strdup(str);
	else
		dup = ft_strnew(0);
	if (dup != NULL && is_there(wflag, '.'))
	//if ((dup != NULL && is_there(wflag, '.')) || (str == NULL && !is_there(wflag, '.')))
		dup[atoi_precision(wflag)] = '\0';
	retour = 0;
	toprint = atoi_wflag(wflag) - ft_strlen(dup);//attention quand strlen renvoi 0
	if (toprint >= 1)
		retour = toprint;
	if (is_there(wflag, '-'))
		ft_putstr(dup);
	if (is_flag_zero(wflag) && !is_there(wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(wflag, '-'))
		ft_putstr(dup);
	retour += ft_strlen(dup);
	free(dup);
	return (retour);
}
