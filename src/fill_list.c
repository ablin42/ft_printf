#include "../includes/printf.h"

t_arg	*add_type_arg(t_arg *lst, char flag, int id)
{
	t_arg	*element;
	t_arg	*tmp;

	if ((element = malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	tmp = lst;
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
			*lst = add_type_arg(*lst, format[i + 1], id);
			//condition to go until end of flag aka the flag's letter
			i = i + 2;
			id++;
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
		if (tmp->flag == 'c')
			tmp->type.c = (char)va_arg(ap, int);
		else if (tmp->flag == 'u')
			tmp->type.u = (int)va_arg(ap, int);
		else if (tmp->flag == 's')
			tmp->type.str = (char *)va_arg(ap, char *);
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	return (lst);
}



















