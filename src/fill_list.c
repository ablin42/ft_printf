#include "../includes/printf.h"

t_arg	*add_type_arg(t_arg *lst, char flag, const char * restrict format)
{
	t_arg	*element;
	t_arg	*tmp;
	static	int id;// can remove later

	if ((element = malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	tmp = lst;
	element->flag = flag;
	element->id = id; //can remove later
	id++; //same
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
	int		i;

	i = 0;
	*lst = NULL;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			*lst = add_type_arg(*lst, format[i], format);
		}
		i++;
	}
}

t_arg	*cycle_arg(t_arg *lst, const char * restrict format, va_list ap)
{
	int		i;
	t_arg	*tmp;

	i = 0;
	tmp = lst;
	while (i < count_flags(format))
	{
		ft_putchar(tmp->flag);
		ft_putstr(" | ");
		ft_putnbr(tmp->id);
		ft_putchar('\n');
		if (tmp->flag == 'c')
			tmp->type.c = (char)va_arg(ap, int);
		else if (tmp->flag == 'u')
			tmp->type.u = (int)va_arg(ap, int);
		else if (tmp->flag == 's')
			tmp->type.str = (char *)va_arg(ap, char *);
		tmp = tmp->next;
		i++;
	}
	return (lst);
}



















