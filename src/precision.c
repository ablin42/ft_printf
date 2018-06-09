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

int		flag_and_precision(char *wflag, int nb)
{
	int		toprint;
	int		retour;
	int		nbprint;

	nbprint = nb;
	retour = divide_nb(nb, 10);
	toprint = atoi_wflag(wflag) - atoi_precision(wflag);//prend pas en compte taille du nbr
	if (nbprint < 0)
		toprint--;
	while (toprint > 0)
	{
		ft_putchar(' ');
		toprint--;
	}
	if (nbprint < 0)
	{
		nbprint *= -1;
//		retour++;
		ft_putchar('-');
	}
	toprint = atoi_precision(wflag) - retour;// - (ft_atoi_wflag(wflag) - ft_atoi_precision(wflag));
	to_print('0', toprint);
	retour = atoi_wflag(wflag);
	ft_putnbr(nbprint);
	return (retour);
}

int		int_precision(char *wflag, int nb)
{
	int		toprint;
	int		retour;
	int		nbprint;

	nbprint = nb;
	retour = divide_nb(nb, 10);
	toprint = atoi_precision(wflag) - retour;
	if (nbprint < 0)
	{
		ft_putchar('-');
		nbprint *= -1;
		retour++;
	}
	if (toprint > 0)
		retour += toprint;
	to_print('0', toprint);
	ft_putnbr(nbprint);
	return (retour);
}
