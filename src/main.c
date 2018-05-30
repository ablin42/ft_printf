#include "../includes/printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

#include "print_format.c"
#include "nb_padding.c"
#include "str_padding.c"
#include "print.c"
#include "utils.c"

int		main()
{
	//*/ FLAGS TESTS STR
	//flags '0' & '+' & ' ' & maybe '#' results in undefined with %s

	printf("%d", ft_printf("<%10s><%10s><%-10s>", "Harbinger", "is their", "God."));
	printf("%d", printf("\n<%10s><%10s><%-10s>\n\n", "Harbinger", "is their", "God."));
	
	printf("%d", ft_printf("<%5s><%1s><%-10s>", "Embrace", "", "entropy"));
	printf("%d", printf("\n<%5s><%1s><%-10s>\n\n", "Embrace", "", "entropy"));

	printf("%d", ft_printf("<%-5s><%10s><%-3s>", "Death comes", "at last", "..."));
	printf("%d", printf("\n<%-5s><%10s><%-3s>\n\n", "Death comes", "at last", "..."));
	
	printf("%d", ft_printf("<This\tis\nan escape\\sequence.>"));
	printf("%d", printf("\n<This\tis\nan escape\\sequence.>\n\n"));

	printf("%d", ft_printf("<this %s is 100%% aids>", "shit"));
	printf("%d", printf("\n<this %s is 100%% aids>\n\n", "shit"));
	//*/

	/*/ FLAGS TESTS INT
	printf("%d", ft_printf("<%+---+3d><%--++3d>", 123, -123);
	printf("%d", printf("\n<%+---+3d><%--++3d>\n\n", 123, -123);
	
	printf("%d", ft_printf("<%3d><%4d><%3d>", 42, -42, -42);
	printf("%d", printf("\n<%3d><%4d><%3d>\n\n", 42, -42, -42);

	printf("%d", ft_printf("<%+5d><%+5d><%+5d><%-+5d><%-+5d><%-+5d>", 0, +0, -0, 0, +0, -0));
	printf("%d", printf("\n<%+5d><%+5d><%+5d><%-+5d><%-+5d><%-+5d>\n\n", 0, +0, -0, 0, +0, -0));
	
	printf("%d", ft_printf("<%+02d><%+02d><%+03d><%+03d><%+05d><%+05d>", 42, -42, 42, -42, 42, -42));
	printf("%d", printf("\n<%+02d><%+02d><%+03d><%+03d><%+05d><%+05d>\n\n", 42, -42, 42, -42, 42, -42));

	printf("%d", ft_printf("<%+4d><%+4d><%+5d><%+5d><%+6d><%+6d>", 1998, -1998, 1998, -1998, 1998, -1998));
	printf("%d", printf("\n<%+4d><%+4d><%+5d><%+5d><%+6d><%+6d>\n\n", 1998, -1998, 1998, -1998, 1998, -1998));
	
	printf("%d", ft_printf("<%+-4d><%+-4d><%+-5d><%+-5d><%+-6d><%+-6d>", 1998, -1998, 1998, -1998, 1998, -1998));
	printf("%d", printf("\n<%+-4d><%+-4d><%+-5d><%+-5d><%+-6d><%+-6d>\n\n", 1998, -1998, 1998, -1998, 1998, -1998));
	
	printf("%d", ft_printf("<% 4d><% 4d><% 5d><% 5d><% 6d><% 6d>", 1337, -1337, 1337, -1337, 1337, -1337));
	printf("%d", printf("\n<% 4d><% 4d><% 5d><% 5d><% 6d><% 6d>\n\n", 1337, -1337, 1337, -1337, 1337, -1337));

	printf("%d", ft_printf("<%- 4d><%- 4d><%- 5d><%- 5d><%- 6d><%- 6d>", 1337, -1337, 1337, -1337, 1337, -1337));
	printf("%d", printf("\n<%- 4d><%- 4d><%- 5d><%- 5d><%- 6d><%- 6d>\n\n", 1337, -1337, 1337, -1337, 1337, -1337));
	//*/
	return (0);
}
