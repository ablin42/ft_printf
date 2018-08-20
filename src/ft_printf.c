/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:36:41 by ablin             #+#    #+#             */
/*   Updated: 2018/08/21 00:51:47 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** this function assigns each conversion specifier to a function adress
** and calls to the corresponding function for each flag
*/

void	get_handler(t_arg *lst, va_list ap, int *retour)
{
	int					ret;
	int					i;
	static	const t_fun	handle[6] = {INT, HEX, C, CC, S, SS};

	i = 0;
	ret = 0;
	while (i < 6)
	{
		if (ft_strchr(handle[i].conv, lst->flag) != NULL)
		{
			handle[i].handler(lst, ap, &ret);
			if (ret == -1)
				*retour = 0;
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
	while (lst->flag != 0)
	{
		if (lst->flag != ' ')
		{
			if (ft_strchr(lst->wflag, 'h'))
				lst->mod = H;
			if (ft_strstr(lst->wflag, "hh"))
				lst->mod = HH;
			if (ft_strchr(lst->wflag, 'l'))
				lst->mod = L;
			if (ft_strstr(lst->wflag, "ll"))
				lst->mod = LL;
			if (ft_strchr(lst->wflag, 'j'))
				lst->mod = J;
			if (ft_strchr(lst->wflag, 'z'))
				lst->mod = Z;
			if ((lst->flag == 'c' || lst->flag == 's') && lst->mod == 3)
				lst->flag = ft_toupper(lst->flag);
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
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
		if (*retour == -1)
			return ;
		get_handler(lst, ap, retour);
		if (lst->flag != ' ')
			free(lst->wflag);
		else if (lst->flag == ' ')
			free(lst->type.str);
		free(lst);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}

void	test(t_arg *lst)
{
	while (lst->flag != 0)
	{
		ft_putstr("{");
		ft_putchar(lst->flag);
		ft_putstr("}");
		ft_putchar('\n');
		if (lst->next == NULL)
			break ;
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
	test(lst);
	get_length_mod(lst);
	cycle_arg(lst, ap, &retour);
	return (retour);
}
