#include "../includes/printf.h"

void	test(t_arg *lst)
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
		if (lst->flag == 's' || lst->flag == 'q')
		{
			if (lst->flag == 'q' || ft_strcmp(lst->wflag, "") == 0)
				ft_putstr(lst->type.str);
			else
				ft_strpadding(lst->wflag, lst->type.str);
		}
		if (lst->flag == 'd' || lst->flag == 'i')
		{
			if (!is_there(lst->wflag, '-'))
				ft_nbpaddingdata(lst->wflag, lst->type.d);
			if (is_there(lst->wflag, '-') && !is_there(lst->wflag, ' '))
				ft_leftjustify(lst->wflag, lst->type.d);//int for now
			if (is_there(lst->wflag, '-') && is_there(lst->wflag, ' '))
				ft_leftjustifyblank(lst->wflag, lst->type.d);
		}
		if (lst->flag == 'l')
			ft_putlong(lst->type.l);
		if (lst->flag == 'z')
			ft_putulong(lst->type.z);
		ft_putchar('\n');
		if (lst->next == NULL)
			break;
		lst = lst->next;
	}
}

void	test2(t_arg *lst)
{
	while (lst->flag != 0)
	{
		if (lst->flag == 'c' || lst->flag == '%')
			ft_putchar(lst->type.c);
		if (lst->flag == 's' || lst->flag == 'q')
		{
			if (lst->flag == 'q' || ft_strcmp(lst->wflag, "") == 0)
				ft_putstr(lst->type.str);
			else
				ft_strpadding(lst->wflag, lst->type.str);
		}
		if (lst->flag == 'd' || lst->flag == 'i')
		{
			if (!is_there(lst->wflag, '-'))
				ft_nbpaddingdata(lst->wflag, lst->type.d);
			if (is_there(lst->wflag, '-') && !is_there(lst->wflag, ' '))
				ft_leftjustify(lst->wflag, lst->type.d);//int for now
			if (is_there(lst->wflag, '-') && is_there(lst->wflag, ' '))
				ft_leftjustifyblank(lst->wflag, lst->type.d);
		}
		if (lst->flag == 'l')
			ft_putlong(lst->type.l);
		if (lst->flag == 'z')
			ft_putulong(lst->type.z);
		if (lst->next == NULL)
			break;
		lst = lst->next;
	}
}
