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

/*
 * this function handle the '#' flag
*/

int		htag(t_arg *lst, int signe, int mode)
{
	if (lst->flag == 'p')
	{
		if (mode == 1)
			ft_putstr("0x");
		return (2);
	}
	if (is_there(lst->wflag, '#'))
	{
		if ((lst->flag == 'o' || lst->flag == 'O') && (signe != 0 || (signe == 0 &&
			is_there(lst->wflag, '.') && get_preci(lst->wflag) == 0)))
		{
			if (mode == 1)
				ft_putchar('0');
			return (1);
		}
		else if (lst->flag == 'x' && signe != 0)
		{
			if (mode == 1)
				ft_putstr("0x");
			return (2);
		}
		else if (lst->flag == 'X' && signe != 0)
		{
			if (mode == 1)
				ft_putstr("0X");
			return (2);
		}
	}
	return (0);
}

/*
 * this function prints strings and handle the NULL cases
*/

int		putstr_exc(char *dup, char *str, char *wflag)
{
	int		i;

	i = 0;
	if ((str == NULL || str == 0) && !is_there(wflag, '.'))
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(dup);
	return (0);
}

/*
 * this function handle the flags and print the result for strings with args
*/

int		str_handler(t_arg *lst, va_list ap)
{
	int		toprint;
	int		retour;
	char	*dup;
	char	*str;

	str = va_arg(ap, char *);
	if (str != NULL && str != 0)
		dup = ft_strdup(str);
	else
		dup = ft_strnew(0);
	if (dup != NULL && is_there(lst->wflag, '.'))
		dup[get_preci(lst->wflag)] = '\0';
	retour = 0;
	toprint = get_pad(lst->wflag) - ft_strlen(dup);//attention quand strlen renvoi 0
	if (toprint >= 1)
		retour = toprint;
	if (is_there(lst->wflag, '-'))
		retour += putstr_exc(dup, str, lst->wflag);
	if (is_flag_zero(lst->wflag) && !is_there(lst->wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(lst->wflag, '-'))
		retour += putstr_exc(dup, str, lst->wflag);
	free(dup);
	return (retour + ft_strlen(dup));
}

/*
 * this function prints strings without args
*/

int		str_noflag(t_arg *lst, va_list ap)
{
	int		retour;

	retour = putstr_exc(lst->type.str, lst->type.str, "NOFLAG");
	return (ft_strlen(lst->type.str) + retour);
}
