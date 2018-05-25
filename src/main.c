#include "../includes/printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

#include "print_format.c"
#include "padding.c"
#include "print.c"
#include "utils.c"

int		main()
{
	//*/ FLAGS TESTS
	ft_printf("<%05d><%05d>", 42, -42);
	printf("\n<%05d><%05d>\n\n", 42, -42);

	ft_printf("<%-+5d><%+5d>", 42, -42);
	printf("\n<%-+5d><%+5d>\n\n", 42, -42);

	ft_printf("<%0+5d><%0+5d>", 42, -42);
	printf("\n<%0+5d><%0+5d>\n\n", 42, -42);

	ft_printf("<%-+5d><%-+5d><%-+5d>", 0, +0, -0);
	printf("\n<%-+5d><%-+5d><%-+5d>\n\n", 0, +0, -0);

	ft_printf("<%+5d><%+5d><%+5d>", 0, +0, -0);
	printf("\n<%+5d><%+5d><%+5d>\n\n", 0, +0, -0);

	ft_printf("<%+---+5d><%--++5d>", 1998, -1998);
	printf("\n<%+---+5d><%--++5d>\n\n", 1998, -1998);
	
	ft_printf("<%+4d><%+-4d>", 1998, -1998);
	printf("\n<%+4d><%+-4d>\n\n", 1998, -1998);

	ft_printf("<%+6d><%+-6d>", 1998, -1998);
	printf("\n<%+6d><%+-6d>\n\n", 1998, -1998);
	//*/
	return (0);
}
