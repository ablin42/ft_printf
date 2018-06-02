/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:32:10 by ablin             #+#    #+#             */
/*   Updated: 2018/06/02 21:44:08 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		print_integer(t_arg *lst, int retour)
{
	if (is_there(lst->wflag, '.') &&
			ft_atoi_precision(lst->wflag) >= ft_atoi_wflag(lst->wflag))
		retour = ft_intprecision(lst->wflag, lst->type.d);
	else if (is_there(lst->wflag, '.')
			&& ft_atoi_precision(lst->wflag) < ft_atoi_wflag(lst->wflag))
		retour = ft_flagandprecision(lst->wflag, lst->type.d);
	else if (!is_there(lst->wflag, '-'))
		retour = ft_nbpaddingdata(lst->wflag, lst->type.d);
	if (is_there(lst->wflag, '-') && !is_there(lst->wflag, ' ') &&
			ft_atoi_wflag(lst->wflag) > 0)
		retour = ft_leftjustify(lst->wflag, lst->type.d);
	if (is_there(lst->wflag, '-') && is_there(lst->wflag, ' ')
			&& ft_atoi_wflag(lst->wflag) > 0)
		retour = ft_leftjustifyblank(lst->wflag, lst->type.d);
	return (retour);
}

void	test(t_arg *lst, int *retour)
{
	while (lst->flag != 0)
	{
		ft_putnbr(lst->id);
		ft_putstr(" | ");
		ft_putchar(lst->flag);
		ft_putstr(" | ");
		ft_putstr(lst->wflag);
		ft_putstr(" | ");
		if (lst->flag == 'c' || lst->flag == '%')
			ft_putchar(lst->type.c);
		if (lst->flag == 's' || lst->flag == 'q')
		{
			if (lst->flag == 'q' || ft_strcmp(lst->wflag, "") == 0)
				ft_putstr(lst->type.str);
			else
				ft_strpadding(lst->wflag,
						ft_strprecision(lst->wflag, lst->type.str));
		}
		if (lst->flag == 'd' || lst->flag == 'i')
			*retour += print_integer(lst, *retour);
		if (lst->flag == 'l')
			ft_putlong(lst->type.l);
		if (lst->flag == 'z')
			ft_putulong(lst->type.z);
		ft_putchar('\n');
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}

void	test2(t_arg *lst, int *retour)
{
	while (lst->flag != 0)
	{
		if (lst->flag == 'c' || lst->flag == '%')
		{
			ft_putchar(lst->type.c);
			*retour += 1;
		}
		if (lst->flag == 's' || lst->flag == 'q')
		{
			if (lst->flag == 'q' || ft_strcmp(lst->wflag, "") == 0)
			{
				ft_putstr(lst->type.str);
				*retour += ft_strlen(lst->type.str);
			}
			else
				*retour += ft_strpadding(lst->wflag, ft_strprecision(lst->wflag,
		lst->type.str)) + ft_strlen(ft_strprecision(lst->wflag, lst->type.str));
			//^mettre ca dans strpadding ou a l'insertion des listes, check pour les leaks, double call
		}
		if (lst->flag == 'd' || lst->flag == 'i')
			*retour += print_integer(lst, *retour);
		if (lst->flag == 'l')
			ft_putlong(lst->type.l);
		if (lst->flag == 'z')
			ft_putulong(lst->type.z);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}
