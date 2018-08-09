/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:40:33 by ablin             #+#    #+#             */
/*   Updated: 2018/08/09 02:54:49 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** this function handle and print the flags for
** the C (wchar_t) conversion specifier
*/

void	print_wchar(t_arg *lst, va_list ap, int *r)
{
	int			toprint;
	int			ret;
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
	*r += ret;
}

/*
** this function prints a wide char string if called with the putwchar function
** else it simply returns the nb of char to be printed if called with wchar_len
*/

int		ft_putwstr_preci(wchar_t *str, char *wflag, int (*func)(wchar_t))
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if ((str == NULL || str == 0) && !is_there(wflag, '.'))
	{
		if (func == ft_putwchar)
			ft_putstr("(null)");
		return (6);
	}
	while (str != NULL && str[i] != '\0')
	{
		if (!is_there(wflag, '.') || (is_there(wflag, '.') &&
		ret + wchar_len(str[i]) <= get_preci(wflag)))
			ret += func(str[i]);
		i++;
	}
	return (ret);
}

/*
** this function prints a wide character string with its padding and precision
*/

void	print_wstr(t_arg *lst, va_list ap, int *r)
{
	int			toprint;
	int			ret;
	int			i;
	wchar_t		*s;

	s = va_arg(ap, wchar_t *);
	i = 0;
	ret = ft_putwstr_preci(s, lst->wflag, wchar_len);
	toprint = get_pad(lst->wflag) - ret;
	if (toprint > 0)
		ret += toprint;
	if (is_there(lst->wflag, '-'))
		ft_putwstr_preci(s, lst->wflag, ft_putwchar);
	if (is_flag_zero(lst->wflag) && !is_there(lst->wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(lst->wflag, '-'))
		ft_putwstr_preci(s, lst->wflag, ft_putwchar);
	*r += ret;
}
