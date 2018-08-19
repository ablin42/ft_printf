/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:36:41 by ablin             #+#    #+#             */
/*   Updated: 2018/08/19 00:49:33 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** this function assigns each conversion specifier to a function adress
** and calls to the corresponding function for each flag
*/

void	get_handler(t_arg *lst, va_list ap, int *retour)
{
	int		ret;
	int		i;
	t_fun	(handle[6]) = {
	{ .conv = "c%", .handler = c_padding },
	{ .conv = "s ", .handler = str_handler },
	{ .conv = "S", .handler = print_wstr },
	{ .conv = "dDi", .handler = int_handler },
	{ .conv = "oOuUxXp", .handler = hex_handler },
	{ .conv = "C", .handler = print_wchar }};

	i = 0;
	ret = 0;
	while (i < 6)
	{
		if (ft_strchr(handle[i].conv, lst->flag) != NULL)
		{
			handle[i].handler(lst, ap, &ret);
			*retour += ret;
			return ;
		}
		i++;
	}
	c_padding(lst, ap, &ret);
	*retour += ret;
	return ;
}

/*
** this function fetches the length modifier and place it in our list
*/

void	get_length_mod(t_arg *lst)
{
	t_arg	*tmp;

	tmp = lst;
	while (tmp->flag != 0)
	{
		if (tmp->flag != ' ')
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
** this function cycle the list and calls to get handler for each list member
** it frees the list after calling to get_handler
*/

void	cycle_arg(t_arg *lst, va_list ap, int *retour)
{
	while (lst->flag != 0)
	{
		get_handler(lst, ap, retour);
		if (lst->flag != ' ')
			free(lst->wflag);
		else if (lst->flag == ' ')
			free(lst->type.str);
		free(lst);
		if (lst->next == NULL)
			break;
		lst = lst->next;
	}
}

/*
** this function calls the other main functions, free the list and return
** the total nb of characters printed
*/

int		ft_printf(const char *restrict format, ...)
{
	t_arg	*lst;
	int		retour;
	va_list	ap;

	retour = 0;
	if (ft_strcmp(format, "") == 0)
		return (0);
	va_start(ap, format);
	fetch_arg(&lst, format);
	get_length_mod(lst);
	cycle_arg(lst, ap, &retour);
	return (retour);
}
