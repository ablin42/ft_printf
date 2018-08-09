/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:36:14 by ablin             #+#    #+#             */
/*   Updated: 2018/08/09 02:36:30 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** this function add each printf arg to a list with its corresponding flags
*/

t_arg	*add_arg(t_arg *lst, char flag, char *wflag)
{
	t_arg	*element;
	t_arg	*tmp;

	if ((element = (t_arg *)malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	tmp = lst;
	element->wflag = wflag;
	element->flag = flag;
	element->base = 10;
	if (flag == 'x' || flag == 'X' || flag == 'p')
		element->base = 16;
	if (flag == 'o' || flag == 'O')
		element->base = 8;
	if (flag == '%')
		element->type.c = '%';
	element->next = NULL;
	if (lst == NULL)
		return (element);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (lst);
}

/*
** this function add non arguments from format to the list
*/

t_arg	*add_str(t_arg *lst, char *format, char *str)
{
	t_arg	*element;
	t_arg	*tmp;

	if ((element = (t_arg *)malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	tmp = lst;
	element->wflag = "NOFLAG";
	element->flag = ' ';
	element->type.str = str;
	element->next = NULL;
	if (lst == NULL)
		return (element);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (lst);
}

/*
** this function cycle the printf arguments and call the corresponding function
** to place them in a list
*/

void	fetch_arg(t_arg **lst, const char *restrict format)
{
	int		i;
	int		st;

	i = 0;
	*lst = NULL;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i] != '\0')
		{
			i++;
			st = i;
			while (SPEC(format[i]))
				i++;
			*lst = add_arg(*lst, format[i], ft_strsub(format, st, (i - st)));
			i++;
		}
		if (format[i] != '%' && format[i] != '\0')
		{
			st = i;
			while (format[i] != '%' && format[i] != '\0')
				i++;
			*lst = add_str(*lst, (char*)format, ft_strsub(format, st, i - st));
		}
	}
}
