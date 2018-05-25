/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:23:59 by ablin             #+#    #+#             */
/*   Updated: 2018/05/17 22:19:36 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_arg	*add_type_arg(t_arg *lst, char flag, char *wflag, int id)
{
	t_arg	*element;
	t_arg	*tmp;

	if ((element = malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	tmp = lst;
	element->wflag = wflag;
	element->flag = flag;
	element->id = id;
	element->next = NULL;
	if (lst == NULL)
		return (element);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (lst);
}

t_arg	*add_string_noarg(t_arg *lst, const char * restrict format, int start, int end, int id)
{
	t_arg	*element;
	t_arg	*tmp;

	if ((element = malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	tmp = lst;
	element->wflag = "NULL";//segfault here cause of printing condition 
	element->flag = 'q';
	element->id = id;
	element->type.str = ft_strsub(format, start, (end - start)); //check for memory leaks
	element->next = NULL;
	if (lst == NULL)
		return (element);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (lst);
}

void	lst_type_arg(t_arg **lst, const char * restrict format)
{
	static int id;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	*lst = NULL;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i] != '\0')
		{
			start = i + 1;
			while (SPEC(format[i]))//apply define
				i++;
			end = i;
			*lst = add_type_arg(*lst, format[end], ft_strsub(format, start, (end - start)), id);
			id++;
			i++;
		}
		if (format[i] != '%' && format[i] != '\0')
		{
			start = i;
			while (format[i] != '%' && format[i] != '\0')
				i++;
			end = i;
			*lst = add_string_noarg(*lst, format, start, end, id);
			id++;
		}
	}
}

t_arg	*cycle_arg(t_arg *lst, va_list ap)
{
	int		i;
	t_arg	*tmp;

	i = 0;
	tmp = lst;
	while (tmp->flag != 0) //moche
	{
		if (tmp->flag == 'c') //char
			tmp->type.c = (char)va_arg(ap, int);
		else if (tmp->flag == 'd' || tmp->flag == 'i') //int
			tmp->type.d = (signed int)va_arg(ap, int); //signed
		else if (tmp->flag == 's') //string
			tmp->type.str = (char *)va_arg(ap, char *);
		else if (tmp->flag == 'l') //long long
			tmp->type.l = (long long)va_arg(ap, long long);
		else if (tmp->flag == 'z')//unsigned long long
			tmp->type.z = (unsigned long long)va_arg(ap, unsigned long long);
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	return (lst);
}
