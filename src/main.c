#include "../includes/printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

#include "print_format.c"

void	test(t_arg *lst)
{
	while (lst->flag != 0)
	{
		ft_putnbr(lst->id);
		ft_putstr(" | ");
		ft_putchar(lst->flag);
		ft_putstr(" | ");
		if (lst->flag == 'c')
			ft_putchar(lst->type.c);
		if (lst->flag == 's' || lst->flag == 'q')
			ft_putstr(lst->type.str);
		if (lst->flag == 'd')
			ft_putnbr(lst->type.d);
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
		if (lst->flag == 'c')
			ft_putchar(lst->type.c);
		if (lst->flag == 's' || lst->flag == 'q')
			ft_putstr(lst->type.str);
		if (lst->flag == 'd')
			ft_putnbr(lst->type.d);
		if (lst->flag == 'l')
			ft_putlong(lst->type.l);
		if (lst->flag == 'z')
			ft_putulong(lst->type.z);
		if (lst->next == NULL)
			break;
		lst = lst->next;
	}
}

int		main()
{
	ft_putfloat(42.09);
	printf("\n%f\n", 42.09);
//	ft_printf("[PTDR ]%s[ OK ]%c[ ]%d", "COWAAAAAAARDS!", '@', 42);
//	printf("\n[PTDR ]%s[ OK ]%c[ ]%d \n", "COWAAAAAAARDS!", '@', 42);
	return (0);
}
