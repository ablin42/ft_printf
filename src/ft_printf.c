/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:24:08 by ablin             #+#    #+#             */
/*   Updated: 2018/06/02 21:20:31 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include "../includes/printf.h"
#include "fill_list.c"

/*
 * this function assigns each conversion specifier to a function adress
 * and calls to the corresponding function for each flag
*/

int		get_handler(t_arg *lst, va_list ap)
{
	int		i;
	t_fun	(handle[7]) = {
	{ .conv = "c%", .handler = c_padding },
	{ .conv = "s", .handler = str_handler },
	{ .conv = " ", .handler = str_noflag },
	{ .conv = "S", .handler = print_wstr },
	{ .conv = "dDi", .handler = int_handler },
	{ .conv = "oOuUxXp", .handler = hex_handler },
	{ .conv = "C", .handler = print_wchar }};

	i = 0;
	while (i < 7)
	{
		if (ft_strchr(handle[i].conv, lst->flag) != NULL)
			return (handle[i].handler(lst, ap));
		i++;
	}
	return (c_padding(lst, ap));
}

/*
 * this function fetches the length modifier and place it in our list
*/

void	get_length_mod(t_arg *lst)
{
	t_arg	*tmp;

	tmp = lst;
	while (tmp->flag != 0)
	{
		if (lst->flag != ' ')
		{
			if (ft_strchr(tmp->wflag, 'h'))
				tmp->mod = H;
			if (ft_strstr(tmp->wflag, "hh"))
				tmp->mod = HH;
			if (ft_strchr(tmp->wflag, 'l'))
				tmp->mod = L;
			if (ft_strstr(tmp->wflag, "ll"))
				tmp->mod = LL;
			if (ft_strchr(tmp->wflag, 'j'))
				tmp->mod = J;
			if (ft_strchr(tmp->wflag, 'z'))
				tmp->mod = Z;
			if ((tmp->flag == 'c' || tmp->flag == 's') && tmp->mod == 3)
				tmp->flag = ft_toupper(tmp->flag);
		}
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
}

/*
 * this function cycle the list and calls to get handler for each list member
*/

void	cycle_arg(t_arg *lst, va_list ap, int *retour)
{
	while (lst->flag != 0)
	{
		*retour += get_handler(lst, ap);
		if (lst->next == NULL)
			break;
		lst = lst->next;
	}
}

/*
 * this function calls the other main functions, free the list and return
 * the total nb of characters printed
*/

int		ft_printf(const char *restrict format, ...)
{
	t_arg	*lst;
	int		retour;
	va_list ap;

	retour = 0;
	if (ft_strcmp(format, "") == 0)
		return (0);
	va_start(ap, format);
	fetch_arg(&lst, format);
	get_length_mod(lst);
	cycle_arg(lst, ap, &retour);
	free(lst);
	return (retour);
}
