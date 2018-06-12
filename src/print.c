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
			atoi_precision(lst->wflag) >= atoi_wflag(lst->wflag))
		retour = int_precision(lst->wflag, lst->type.d);
	else if (is_there(lst->wflag, '.')
			&& atoi_precision(lst->wflag) < atoi_wflag(lst->wflag))
		retour = flag_and_precision(lst->wflag, lst->type.d);
	else if (!is_there(lst->wflag, '-'))
		retour = nb_padding_data(lst->wflag, lst->type.d);
	if (is_there(lst->wflag, '-') && !is_there(lst->wflag, ' ') &&
			atoi_wflag(lst->wflag) > 0)
		retour = leftjustify(lst->wflag, lst->type.d);
	if (is_there(lst->wflag, '-') && is_there(lst->wflag, ' ')
			&& atoi_wflag(lst->wflag) > 0)
		retour = leftjustifyblank(lst->wflag, lst->type.d);
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
				str_padding(lst->wflag,
						str_precisionx(lst->wflag, lst->type.str));
		}
		if (lst->flag == 'd' || lst->flag == 'i')
			*retour += print_integer(lst, *retour);
		if (lst->flag == 'l')
			ft_putlonglong(lst->type.l);
		if (lst->flag == 'U')
			ft_putulong(lst->type.U);
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
		if (lst->flag == 'C')
			*retour += ft_putwchar(lst->type.d);
		//*retour += print_wchar(lst->type.d);
		if (lst->flag == 's' || lst->flag == 'q')
		{
			if (lst->flag == 'q' || ft_strcmp(lst->wflag, "") == 0)
			{
				ft_putstr(lst->type.str);
				if (lst->type.str == NULL || lst->type.str == 0)
					*retour += 6;
				else
					*retour += ft_strlen(lst->type.str);
			}
			else
				*retour += str_padding(lst->wflag, str_precisionx(lst->wflag,
		lst->type.str)) + ft_strlen(str_precisionx(lst->wflag, lst->type.str));
			//^mettre ca dans strpadding ou a l'insertion des listes, check pour les leaks, double call
		}
		if (lst->flag == 'S')
			*retour += ft_putwstr(lst->type.S);
		if (lst->flag == 'd' || lst->flag == 'i')
			*retour += print_integer(lst, *retour);
		if (lst->flag == 'D')
			*retour += ft_putlonglong(lst->type.D);
		if (lst->flag == 'u')
			*retour += ft_putulong(lst->type.x);//+=retour
		if (lst->flag == 'x' || lst->flag == 'X')
			*retour += hex_oct_handler(lst->wflag, lst->type.x, lst->flag);
		if (lst->flag == 'o')
			*retour += hex_oct_handler(lst->wflag, lst->type.o, lst->flag);
		if (lst->flag == 'U')
			*retour += ft_putulong(lst->type.U);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}
