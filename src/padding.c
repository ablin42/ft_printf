/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:23:42 by ablin             #+#    #+#             */
/*   Updated: 2018/07/08 01:23:53 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
 * this function handle the space and the '+' flag for numbers
*/

int		blank_and_sign(t_arg *lst, uintmax_t size, int signe, int toprint)
{
	int		retour;

	retour = 0;
//	if (get_preci(lst->wflag) > size && is_there(lst->wflag, '#') &&
//	(lst->flag == 'o' || lst->flag == 'O'))
//		toprint++;
	if (((is_there(lst->wflag, '+')) || signe == -1 ||
	is_there(lst->wflag, ' ')) && FLAG_EXC)
		toprint--;
	if (is_there(lst->wflag, '+') && signe != -1 && is_flag_zero(lst->wflag)
	&& FLAG_EXC)
		ft_putchar('+');
	if (!is_there(lst->wflag, '-') && !is_flag_zero(lst->wflag))
		to_print(' ', toprint);
	if (is_there(lst->wflag, '+') && signe != -1 && !is_flag_zero(lst->wflag)
	&& FLAG_EXC)
		ft_putchar('+');
	else if (is_there(lst->wflag, ' ') && !is_there(lst->wflag, '+') && signe != -1 && FLAG_EXC)
		ft_putchar(' ');
	if (toprint > 0)
		retour += toprint;
	if ((is_there(lst->wflag, ' ') || is_there(lst->wflag, '+') || signe == -1)
	&& FLAG_EXC)
		retour++;
	return (retour);
}

/*
 * this function handle the precision and the '0' flag for numbers
*/

int		precision_and_zero(t_arg *lst, uintmax_t size, int signe)
{
	int		toprint;

	toprint = get_pad(lst->wflag) - size - htag(lst, signe, 0);
	if (size < get_preci(lst->wflag))
		toprint = get_pad(lst->wflag) - get_preci(lst->wflag);
	if (is_there(lst->wflag, '+') || signe < 0 || is_there(lst->wflag, ' '))
		toprint--;
	htag(lst, signe, 1);
	if (signe < 0)
		ft_putchar('-');
	if (is_flag_zero(lst->wflag) && !is_there(lst->wflag, '-'))
		to_print_s(toprint, lst->wflag);
	if (is_there(lst->wflag, '.') && signe == 0 &&
	get_preci(lst->wflag) == 0)
		return (htag(lst, signe, 0));
	toprint = get_preci(lst->wflag) - size;
	if ((lst->flag == 'o' || lst->flag == 'O') && is_there(lst->wflag, '#'))
		toprint = get_preci(lst->wflag) - size - htag(lst, signe, 0);
	to_print('0', toprint);
	if (toprint > 0 && is_there(lst->wflag, '.'))
		return (toprint);
	return (0);
}

/*
 * this function handle the '-' flag
*/

int		minus_flag(t_arg *lst, int toprint, int signe)
{
	if (is_there(lst->wflag, '-'))
	{
		if (htag(lst, signe, 0) == 0)
			if (lst->flag != 'u' && lst->flag != 'U' && lst->flag != 'O' && (is_there(lst->wflag, '+') || is_there(lst->wflag, ' ')
				|| signe == -1))
				toprint--;
		to_print(' ', toprint);
	}
	if (is_there(lst->wflag, '#') && htag(lst, signe, 0) != 0 && lst->flag != 'O' &&
	(is_there(lst->wflag, '+') || is_there(lst->wflag, ' ')))
		return (1);
	return (0);
}
