/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:23:59 by ablin             #+#    #+#             */
/*   Updated: 2018/06/02 21:25:51 by ablin            ###   ########.fr       */
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
	ft_putchar('[');
	ft_putchar(flag);
	ft_putchar(']');
	element->base = 10;
	if (flag == 'x' || flag == 'X' || flag == 'p')
		element->base = 16;
	if (flag == 'o' || flag == 'O')
		element->base = 8;
	if (flag == '%')
		element->type.c = '%';
	element->id = id;
	element->next = NULL;
	if (lst == NULL)
		return (element);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (lst);
}

t_arg	*add_string_noarg(t_arg *lst, char *format, int start, int end, int id)
{
	t_arg	*element;
	t_arg	*tmp;

	if ((element = malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	tmp = lst;
	element->wflag = "NOFLAG";
	element->flag = ' ';
	element->id = id;
	element->type.str = ft_strsub(format, start, (end - start));
	//check for memoty leaks above
	element->next = NULL;
	if (lst == NULL)
		return (element);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (lst);
}

void	lst_type_arg(t_arg **lst, const char *restrict format)
{
	static int id;
	int			i;
	int			start;
	int			end;

	i = 0;
	start = 0;
	end = 0;
	*lst = NULL;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i] != '\0')
		{
			i++;
			start = i;
			while (SPEC(format[i]))
				i++;
			end = i;
			*lst = add_type_arg(*lst, format[end], ft_strsub(format, start, (end - start)), id);
			//+1 au dessus donne le flag a la fin du wflag
			id++;
			i++;
		}
		if (format[i] != '%' && format[i] != '\0')
		{
			start = i;
			while (format[i] != '%' && format[i] != '\0')
				i++;
			end = i;
			*lst = add_string_noarg(*lst, (char*)format, start, end, id);
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
	//condition while plutot moche
	while (tmp->flag != 0)
	{
		if (tmp->flag == 'c')
			tmp->type.c = (char)va_arg(ap, int);
		else if (tmp->flag == 'C')
			tmp->type.d = (signed int)va_arg(ap, wchar_t); //signed????
		else if (tmp->flag == 'd' || tmp->flag == 'i')
			tmp->type.d = (signed int)va_arg(ap, int); //signed????
		else if (tmp->flag == 'D')
			tmp->type.D = (long int)va_arg(ap, long int); //signed????
		else if (tmp->flag == 'u')
			tmp->type.x = (unsigned int)va_arg(ap, unsigned int);
		else if (tmp->flag == 's')
			tmp->type.str = (char *)va_arg(ap, char *);
		else if (tmp->flag == 'S')
			tmp->type.S = (signed int*)va_arg(ap, wchar_t*); //signed????
		else if (tmp->flag == 'x' || tmp->flag == 'X')
			tmp->type.x = (unsigned int)va_arg(ap, unsigned int);
		else if (tmp->flag == 'o')
			tmp->type.d = (int)va_arg(ap, int);
		else if (tmp->flag == 'O')
			tmp->type.D = (unsigned long)va_arg(ap, unsigned long);//used to be unsigned long int
		else if (tmp->flag == 'U')
			tmp->type.U = (unsigned long long)va_arg(ap, unsigned long long);
		else if (tmp->flag == 'p')
			tmp->type.D = (unsigned long)va_arg(ap, void*);
		else if (tmp->flag != ' ')
			tmp->type.c = tmp->flag;
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (lst);
}
