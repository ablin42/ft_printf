/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 01:23:18 by ablin             #+#    #+#             */
/*   Updated: 2018/07/08 01:23:20 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
 * this function handle and print the flags for the c conversion specifier
*/

int		c_padding(t_arg *lst, va_list ap)
{
	int		toprint;
	int		ret;
	char	c;

	if (lst->flag == 'c')
		c = va_arg(ap, int);
	else
		c = lst->flag;
	ret = get_pad(lst->wflag);
	if (ret == 0)
		ret = 1;
	toprint = ret - 1;
	if (is_there(lst->wflag, '-'))
		ft_putchar(c);
	if (is_flag_zero(lst->wflag) && !is_there(lst->wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(lst->wflag, '-'))
		ft_putchar(c);
	return (ret);
}

/*
 * this function handle and print the flags for
 * the C (wchar_t) conversion specifier
*/

int		print_wchar(t_arg *lst, va_list ap)
{
	int		toprint;
	int		ret;
	wchar_t		c;

	c = va_arg(ap, wchar_t);
	ret = wchar_len(c);
	toprint = get_pad(lst->wflag) - ret;
	if (toprint > 0)
		ret += toprint;
	if (is_there(lst->wflag, '-'))
		ft_putwchar(c);
	if (is_flag_zero(lst->wflag) && !is_there(lst->wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(lst->wflag, '-'))
		ft_putwchar(c);
	return (ret);
}

/*
 * this function prints wchar_t * and return the nb of char printed
*/

int		ft_putwstr_preci(wchar_t *str, char *wflag)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if ((str == NULL || str == 0) && !is_there(wflag, '.'))
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str != NULL && str[i] != '\0')
	{
		if (!is_there(wflag, '.') || (is_there(wflag, '.') &&
			ret + wchar_len(str[i]) <= get_preci(wflag)))
			ret += ft_putwchar(str[i]);
		i++;
	}
	return (ret);
}

/*
 * this function handle the flags for the S (wchar_t *) conversion specifier
*/

int		print_wstr(t_arg *lst, va_list ap)
{
	int		toprint;
	int		ret;
	int		i;
	wchar_t		*S;

	S = va_arg(ap, wchar_t *);
	i = 0;
	ret = 0;
	if ((S == NULL || S == 0) && !is_there(lst->wflag, '.'))
		ret = 6;
	while (S != NULL && S[i] != '\0')
	{
		if (!is_there(lst->wflag, '.') || (is_there(lst->wflag, '.') &&
			ret + wchar_len(S[i]) <= get_preci(lst->wflag)))
			ret += wchar_len(S[i]);
		i++;
	}
	toprint = get_pad(lst->wflag) - ret;
	if (toprint > 0)
		ret += toprint;
	if (is_there(lst->wflag, '-'))
		ft_putwstr_preci(S, lst->wflag);
	if (is_flag_zero(lst->wflag) && !is_there(lst->wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(lst->wflag, '-'))
		ft_putwstr_preci(S, lst->wflag);
	return (ret);
}