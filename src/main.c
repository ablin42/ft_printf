#include "../includes/printf.h"
#include "../libft/libft.h"
#include <stdarg.h>

void	test(t_arg *lst)
{
	while (lst->next != NULL)
	{
		ft_putchar(lst->flag);
		ft_putstr(" | ");
		ft_putnbr(lst->id);
		ft_putstr(" | ");
		if (lst->flag == 'c')
			ft_putchar(lst->type.c);
		if (lst->flag == 's')
			ft_putstr(lst->type.str);
		if (lst->flag == 'u')
			ft_putnbr(lst->type.u);
		ft_putchar('\n');
		lst = lst->next;
	}
		ft_putchar(lst->flag);
		ft_putstr(" | ");
		ft_putnbr(lst->id);
		ft_putstr(" | ");
		if (lst->flag == 'c')
			ft_putchar(lst->type.c);
		if (lst->flag == 's')
			ft_putstr(lst->type.str);
		if (lst->flag == 'u')
			ft_putnbr(lst->type.u);
		ft_putchar('\n');
}

int		main()
{
	char a[] = "GET UP! FIGHT!";
	char b[] = "BORDEL";
	int  c = -42;
	
	ft_printf("%c %s OK %u %s", 'Y', a, c, b);
	return (0);
}
