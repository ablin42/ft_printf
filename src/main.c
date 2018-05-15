#include "../includes/printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

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
		if (lst->flag == 'u')
			ft_putnbr(lst->type.u);
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
		if (lst->flag == 'u')
			ft_putnbr(lst->type.u);
		if (lst->next == NULL)
			break;
		lst = lst->next;
	}
}

int		main()
{

	ft_printf("[PTDR ]%s[ OK ]%c[ ]%u", "COWAAAAAAARDS!", '@', 42);
//	printf("\n[PTDR ]%%s[ OK ]%%c[ ]%%u\n");
	printf("\n[PTDR ]%s[ OK ]%c[ ]%u\n", "COWAAAAAAARDS!", '@', 42);
	return (0);
}
