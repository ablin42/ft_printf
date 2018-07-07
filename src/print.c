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
		else if (lst->flag == 's' || lst->flag == 'q')
			ft_putstr(lst->type.str);
		else if (lst->flag == 'd' || lst->flag == 'i')
			*retour += padding(lst->wflag, lst->type.d, 10, lst->flag);
		else if (lst->flag == 'U')
			ft_putulong(lst->type.U);
		else
			ft_putstr(lst->type.str);
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
		if (lst->flag == 'c')
			*retour += c_padding(lst->wflag, lst->type.c);
		else if (lst->flag == '%')
			*retour += c_padding(lst->wflag, lst->flag);
		else if (lst->flag == 'C')
			*retour += print_wchar(lst->wflag, lst->type.d);
		else if (lst->flag == 's' || lst->flag == ' ')
		{
		/*	if (lst->flag == ' ') //|| ft_strcmp(lst->wflag, "") == 0)
			{
				ft_putstr(lst->type.str);
				if (lst->type.str == NULL || lst->type.str == 0)
					*retour += 6;
				else
					*retour += ft_strlen(lst->type.str);
			}
			else*/
				*retour += str_handler(lst->wflag, lst->type.str);
		}
		else if (lst->flag == 'S')
			*retour += print_wstr(lst->wflag, lst->type.S);
		else if (lst->flag == 'd' || lst->flag == 'i')
			*retour += padding(lst->wflag, lst->type.d, 10, lst->flag);
		else if (lst->flag == 'D')
			*retour += ft_putlonglong(lst->type.D);
		else if (lst->flag == 'u')
			*retour += padding(lst->wflag, lst->type.x, 10, lst->flag);
		else if (lst->flag == 'x' || lst->flag == 'X')
			*retour += padding(lst->wflag, lst->type.x, 16, lst->flag);
		else if (lst->flag == 'o')
			*retour += padding(lst->wflag, lst->type.d, 8, lst->flag);
		else if (lst->flag == 'O')
			*retour += padding(lst->wflag, lst->type.D, 8, lst->flag);
		else if (lst->flag == 'U')
			*retour += ft_putulong(lst->type.U);
		else if (lst->flag == 'p')
			*retour += padding(lst->wflag, lst->type.D, 16, lst->flag);
		else
			*retour += c_padding(lst->wflag, lst->type.c);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}
