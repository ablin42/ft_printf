/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:23:42 by ablin             #+#    #+#             */
/*   Updated: 2018/06/02 23:27:30 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*str_precisionx(char *wflag, char *str)
{
	int		precision;
	char	*dup;///////////

	if (!is_there(wflag, '.'))
		return (str);
	dup = ft_strdup(str);//nul + leaks
	precision = atoi_precision(wflag);
	if (dup != NULL)
		dup[precision] = '\0';
	return (dup);
}

int		str_padding(char *wflag, char *str)
{
	int		toprint;
	int		retour;

	retour = 0;
	toprint = atoi_wflag(wflag) - ft_strlen(str);//attention quand strlen renvoi 0
	if (toprint >= 1)
		retour = toprint;
	if (is_there(wflag, '-'))
		ft_putstr(str);
	to_print(' ', toprint);
	if (!is_there(wflag, '-'))
		ft_putstr(str);
	return (retour);
}

int		int_precision(char *wflag, int nb)
{
	int		toprint;
	int		retour;
	int		totalprinted;

	totalprinted = 0;
	retour = divide_nb(nb, 10);
	toprint = atoi_wflag(wflag) - retour;
	if (retour < atoi_precision(wflag))
		toprint = atoi_wflag(wflag) - atoi_precision(wflag);
	if (nb < 0)
		toprint--;
	if (toprint > 0)
		totalprinted += toprint;
	to_print(' ', toprint);
	toprint = atoi_precision(wflag) - retour;
	if (toprint > 0)
		totalprinted += toprint;
	if (nb < 0)
	{
		nb *= -1;
		retour++;
		ft_putchar('-');
	}
	to_print('0', toprint);
	ft_putnbr(nb);
	return (retour + totalprinted);
}

int		uint_precision(char *wflag, unsigned long long nb)
{
	int		toprint;
	int		retour;
	int		totalprinted;

	if (nb == 0 && atoi_precision(wflag) == 0)
		return (0);
	totalprinted = 0;
	retour = divide_ll(nb);
	toprint = atoi_wflag(wflag) - retour;
	if (retour < atoi_precision(wflag))
		toprint = atoi_wflag(wflag) - atoi_precision(wflag);
	if (toprint > 0)
		totalprinted += toprint;
	to_print(' ', toprint);
	toprint = atoi_precision(wflag) - retour;
	if (toprint > 0)
		totalprinted += toprint;
	to_print('0', toprint);
	ft_putulong(nb);
	return (retour + totalprinted);
}
























