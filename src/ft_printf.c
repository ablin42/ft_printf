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

int		get_handler(t_arg *lst, va_list ap)
{
	int		retour;
	int		i;

	retour = 0;
	t_fun	(handle[16]) = {
	{ .conv = '%', .handler = c_padding },
	{ .conv = 's', .handler = str_handler2 },
	{ .conv = ' ', .handler = str_handler2 },//fuse ' ' into 's'
	{ .conv = 'S', .handler = print_wstr },
	{ .conv = 'p', .handler = hex_handler },
	{ .conv = 'd', .handler = int_handler },
	{ .conv = 'D', .handler = int_handler },//ft_putlonglong//padding
	{ .conv = 'i', .handler = int_handler },
	{ .conv = 'o', .handler = hex_handler },
	{ .conv = 'O', .handler = hex_handler },
	{ .conv = 'u', .handler = hex_handler },
	{ .conv = 'U', .handler = hex_handler },//ft_putulong//padding
	{ .conv = 'x', .handler = hex_handler },
	{ .conv = 'X', .handler = hex_handler },
	{ .conv = 'c', .handler = c_padding },
	{ .conv = 'C', .handler = print_wchar }};

	while (lst->flag != 0)
	{
		i = 0;
		while (i < 16)
		{
			if (handle[i].conv == lst->flag)
				retour += handle[i].handler(lst, ap);
			else if (i == 15)
				retour += c_padding(lst, ap);
			i++;
		}
		if (lst->next == NULL)
			break;
		lst = lst->next;
	}
	return (retour);
}

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
		}
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
}

int		ft_printf(const char *restrict format, ...)
{
	t_arg	*lst;
	int		retour;
	va_list ap;

	retour = 0;
	if (ft_strcmp(format, "") == 0)
		return (0);
	va_start(ap, format);
	lst_type_arg(&lst, format);
//	lst = cycle_arg(lst, ap);
	get_length_mod(lst);
//	test(lst, &retour);
	retour = get_handler(lst, ap);
//	test2(lst, &retour);
	return (retour);
}
