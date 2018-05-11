#include "../includes/printf.h"
#include "../libft/libft.h"
#include <stdarg.h>

int		main()
{
	char a[] = "GET UP! FIGHT!";
	char b[] = "BORDEL";
	int  c = -42;
	
	ft_printf("%c %s OK %u %s", 'Y', a, c, b);
	return (0);
}
