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
			is_there(lst->wflag, '.') && atoi_precision(lst->wflag) == 0)))
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

int		str_handler(char *wflag, char *str)
{
	int		toprint;
	int		retour;
	char	*dup;

	if (str != NULL && str != 0)
		dup = ft_strdup(str);
	else
		dup = ft_strnew(0);
	if (str != NULL && is_there(wflag, '.'))
		dup[atoi_precision(wflag)] = '\0';
	retour = 0;
	toprint = atoi_wflag(wflag) - ft_strlen(dup);//attention quand strlen renvoi 0
	if (toprint >= 1)
		retour = toprint;
	if (is_there(wflag, '-'))
		retour += putstr_exc(dup, str, wflag);
	if (is_flag_zero(wflag) && !is_there(wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(wflag, '-'))
		retour += putstr_exc(dup, str, wflag);
	retour += ft_strlen(dup);
	free(dup);
	return (retour);
}

int		str_handler2(t_arg *lst, va_list ap)
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
		dup[atoi_precision(lst->wflag)] = '\0';
	retour = 0;
	toprint = atoi_wflag(lst->wflag) - ft_strlen(dup);//attention quand strlen renvoi 0
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

int		str_noflag(t_arg *lst, va_list ap)
{
	int		retour;

	retour = putstr_exc(lst->type.str, lst->type.str, "NOFLAG");
	return (ft_strlen(lst->type.str) + retour);
}
