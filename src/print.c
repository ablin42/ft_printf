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
			*retour += padding(lst->wflag, lst->type.d, 10);
		if (lst->flag == 'U')
			ft_putulong(lst->type.U);
		ft_putchar('\n');
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}

/*void	test2(t_arg *lst, int *retour)
{
	while (lst->flag != 0)
	{
		if (lst->flag == 'c' || lst->flag == '%')
			*retour += c_padding(lst->wflag, lst->type.c);
		if (lst->flag == 'C')
			*retour += print_wchar(lst->wflag, lst->type.d);
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
			*retour += print_wstr(lst->wflag, lst->type.S);
		if (lst->flag == 'd' || lst->flag == 'i')
			*retour += print_integer(lst, *retour);
		if (lst->flag == 'D')
			*retour += ft_putlonglong(lst->type.D);
		if (lst->flag == 'u' && !is_there(lst->wflag, '.'))
			*retour += ft_putulong(lst->type.x);//+=retour
		if (lst->flag == 'u' && is_there(lst->wflag, '.'))
			*retour += test_precision(lst->wflag, lst->type.x, ft_itoa_base_long, 10);//+=retour
			*retour += uint_precision(lst->wflag, lst->type.x);//+=retour
		if (lst->flag == 'x' || lst->flag == 'X')
			*retour += hex_oct_handler(lst->wflag, lst->type.x, lst->flag);
		if (lst->flag == 'o')
			*retour += test_precision(lst->wflag, lst->type.x, ft_itoa_base_long, 8);//+=retour
			*retour += hex_oct_handler(lst->wflag, lst->type.o, lst->flag);
		if (lst->flag == 'O')
			*retour += test_precision(lst->wflag, lst->type.x, ft_itoa_base_long, 8);//+=retour
			*retour += hex_oct_handler(lst->wflag, lst->type.D, lst->flag);
		if (lst->flag == 'U')
			*retour += ft_putulong(lst->type.U);
		if (lst->flag == 'p')
			*retour += print_addr(lst->wflag, lst->type.D);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}*/

void	test2(t_arg *lst, int *retour)
{
	while (lst->flag != 0)
	{
		if (lst->flag == 'c' || lst->flag == '%')
			*retour += c_padding(lst->wflag, lst->type.c);
		if (lst->flag == 'C')
			*retour += print_wchar(lst->wflag, lst->type.d);
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
			*retour += print_wstr(lst->wflag, lst->type.S);
		if (lst->flag == 'd' || lst->flag == 'i')
			*retour += padding(lst->wflag, lst->type.d, 10);
		if (lst->flag == 'D')
			*retour += ft_putlonglong(lst->type.D);
		if (lst->flag == 'u')
			*retour += padding(lst->wflag, lst->type.x, 10);
			//*retour += uint_precision(lst->wflag, lst->type.x);//+=retour
		if (lst->flag == 'x' || lst->flag == 'X')
			*retour += padding(lst->wflag, lst->type.d, 16);
		if (lst->flag == 'o')
			*retour += padding(lst->wflag, lst->type.d, 8);
			//*retour += hex_oct_handler(lst->wflag, lst->type.o, lst->flag);
		if (lst->flag == 'O')
			*retour += padding(lst->wflag, lst->type.d, 8);
			//*retour += hex_oct_handler(lst->wflag, lst->type.D, lst->flag);
		if (lst->flag == 'U')
			*retour += ft_putulong(lst->type.U);
		if (lst->flag == 'p')
			*retour += print_addr(lst->wflag, lst->type.D);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}
