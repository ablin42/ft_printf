//header

#include "../includes/printf.h"

int		hashtag_handler(char *wflag, int nb)//for octal or hex values
{
	int		retour;

	retour = 0;
	if (nb > 0)
	{
		if (is_there(wflag, 'o'))
			ft_putchar('0');
		if (is_there(wflag, 'x'))
			ft_putstr("0x");
		if (is_there(wflag, 'X'))
			ft_putstr("0X");
	}
//	ft_putnbr(nb);//retirer apres
	return (retour);
}
