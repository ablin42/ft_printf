#include "../../includes/libfunc.h"

int			divide_nb_ubase(uintmax_t nb, int base)
{
	int		ret;

	ret = 0;
	while (nb != 0)
	{
		nb /= base;
		ret++;
	}
	return (ret);
}

void	pf_itoa_base(uintmax_t n, int base, char flag)
{
	int		i;
	uintmax_t	nb;
	char	*str;
	char	tab[17];

	if (n == 0)
		return (ft_putchar('0'));
	i = 1;
	nb = divide_nb_ubase(n, base);
	ft_strcpy(tab, "0123456789abcdef");
	if ((str = (char*)malloc(sizeof(char) * (nb + 1))) == NULL)
		return ;
	str[nb] = '\0';
	while (n != 0)
	{
		str[nb - i] = tab[n % base];
		n /= base;
		i++;
	}
	if (flag == 'X')
		ft_putstr(ft_strtoupper(str));
	else
		ft_putstr(str);
	free(str);
}
