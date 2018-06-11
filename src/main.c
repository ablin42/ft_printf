#include "../includes/printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
/*
#include "print_format.c"
#include "nb_padding.c"
#include "precision.c"
#include "print.c"
#include "utils.c"
#include "utils2.c"
#include "ft_itoa_base.c"*/


int		main()
{
/*	wchar_t wch = L'\x3b1';
	wchar_t happy[] = { 0x0061, 0x8161, 0 };
	char unit[] = { 0x00, 0xC6, 0xB8 };
	wchar_t uni[] = { 0x00, 0xC6, 0xB8 };
	wchar_t unix = L'Y';
	wchar_t *unix2 = L"nique ta mere\x3b1";
	char	buffer[1];
	char	buffer2[3];
	//int		length;

	setlocale(LC_ALL, "en_US.UTF-8");
	wctomb(buffer, unix);
	write(1, &unix, 1);
	ft_putstr(" | ");
	write(1, buffer, 1);
	ft_putstr("\n");
	 wcstombs(buffer2, unix2, 170);
	write(1, unix2, 17);
	ft_putstr(" | ");
	ft_putstr(buffer2);ft_putchar('\\');
//	write(1, buffer2, 17);
	ft_putchar('\n');*/
	

	setlocale(LC_ALL, "en_US.UTF-8");
	//*/ WIDE CHAR TESTS
	printf(" %d\n", ft_printf("<--%C-->", L'\x0041'));
	printf(" %d\n\n", printf("<--%C-->", L'\x0041'));

	printf(" %d\n", ft_printf("<--%C-->", L'\x0470'));
	printf(" %d\n\n", printf("<--%C-->", L'\x0470'));

	printf(" %d\n", ft_printf("<--%C-->", L'\x277A'));
	printf(" %d\n\n", printf("<--%C-->", L'\x277A'));
	
	printf(" %d\n", ft_printf("<--%C-->", L'\x1F92E'));
	printf(" %d\n\n", printf("<--%C-->", L'\x1F92E'));
	//*/

	/*/ OCTAL AND HEXADECIMAL TESTS
	printf(" %d\n", ft_printf("<%#x><%#x><%x><%#X><%X> ", 0, 13, 42, 255, 2147483647));
	printf(" %d\n\n", printf("<%#x><%#x><%x><%#X><%X> ", 0, 13, 42, 255, 2147483647));

	printf(" %d\n", ft_printf("<%o><%#o> ", 42, 1998));
	printf(" %d\n\n", printf("<%o><%#o> ", 42, 1998));
	//*/

	/*/ PRECISION TEST STR
	printf(" %d\n", ft_printf("<%.3s><%.3s><%.8s>", "Oof", "theater", "assassinate"));
	printf(" %d\n\n", printf("<%.3s><%.3s><%.8s>", "Oof", "theater", "assassinate"));
	
	printf(" %d\n\n", ft_printf("<%5.3s><%-5.3s><%13.8s>", "Oofballs", "theater", "assassinate"));
	printf(" %d\n\n", printf("<%5.3s><%-5.3s><%13.8s>", "Oofballs", "theater", "assassinate"));
	//*/

	/*/ FLAGS TESTS STR
	printf(" %d\n", ft_printf("<%10s><%10s><%-10s>", "Harbinger", "is their", "God."));
	printf(" %d\n\n", printf("<%10s><%10s><%-10s>", "Harbinger", "is their", "God."));
	
	printf(" %d\n", ft_printf("<%5s><%1s><%-10s>", "Embrace", "", "entropy"));
	printf(" %d\n\n", printf("<%5s><%1s><%-10s>", "Embrace", "", "entropy"));

	printf(" %d\n", ft_printf("<%-5s><%10s><%-3s>", "Death comes", "at last", "..."));
	printf(" %d\n\n", printf("<%-5s><%10s><%-3s>", "Death comes", "at last", "..."));
	
	printf(" %d\n", ft_printf("<This\tis\nan escape\\sequence.>"));
	printf(" %d\n\n", printf("<This\tis\nan escape\\sequence.>"));

	printf(" %d\n", ft_printf("<this %s is 100%% aids %%%%>", "shit"));
	printf(" %d\n\n", printf("<this %s is 100%% aids %%%%>", "shit"));
	//*/

	/*/ PRECISION TEST INT
	printf(" %d\n", ft_printf("<%.0d><%.1d><%.2d><%.2d><%.3d><%.3d>", 42, 42, 42, -42, 42, -42));
	printf(" %d\n\n", printf("<%.0d><%.1d><%.2d><%.2d><%.3d><%.3d>", 42, 42, 42, -42, 42, -42));

	printf(" %d\n", ft_printf("<%5.5d><%5.5d><%3.4d><%4.3d>", 13, -13, -13, 13));
	printf(" %d\n\n", printf("<%5.5d><%5.5d><%3.4d><%4.3d>", 13, -13, -13, 13));

	printf(" %d\n", ft_printf("<%-.5d><%5.5d><%10.5d>", 42, -42, -42));
	printf(" %d\n", printf("<%-.5d><%5.5d><%10.5d>", 42, -42, -42));
	printf("\noublie pas le .0 / .*\n");
	//*/

	/*/ FLAGS TESTS INT
	printf(" %d\n", ft_printf("<%+---+3d><%--++3d>", 123, -123));
	printf(" %d\n\n", printf("<%+---+3d><%--++3d>", 123, -123));
	
	printf(" %d\n", ft_printf("<%3d><%4d><%3d>", 13, -42, -42));
	printf(" %d\n\n", printf("<%3d><%4d><%3d>", 13, -42, -42));

	printf(" %d\n", ft_printf("<%+5d><%+5d><%+5d><%-+5d><%-+5d><%-+5d>", 0, +0, -0, 0, +0, -0));
	printf(" %d\n\n", printf("<%+5d><%+5d><%+5d><%-+5d><%-+5d><%-+5d>", 0, +0, -0, 0, +0, -0));
	
	printf(" %d\n", ft_printf("<%+02d><%+02d><%+03d><%+03d><%+05d><%+05d>", 42, -42, 42, -42, 42, -42));
	printf(" %d\n\n", printf("<%+02d><%+02d><%+03d><%+03d><%+05d><%+05d>", 42, -42, 42, -42, 42, -42));

	printf(" %d\n", ft_printf("<%+4d><%+4d><%+5d><%+5d><%+6d><%+6d>", 1998, -1998, 1998, -1998, 1998, -1998));
	printf(" %d\n\n", printf("<%+4d><%+4d><%+5d><%+5d><%+6d><%+6d>", 1998, -1998, 1998, -1998, 1998, -1998));
	
	printf(" %d\n", ft_printf("<%+-4d><%+-4d><%+-5d><%+-5d><%+-6d><%+-6d>", 1998, -1998, 1998, -1998, 1998, -1998));
	printf(" %d\n\n", printf("<%+-4d><%+-4d><%+-5d><%+-5d><%+-6d><%+-6d>", 1998, -1998, 1998, -1998, 1998, -1998));
	
	printf(" %d\n", ft_printf("<% 4d><% 4d><% 5d><% 5d><% 6d><% 6d>", 1337, -1337, 1337, -1337, 1337, -1337));
	printf(" %d\n\n", printf("<% 4d><% 4d><% 5d><% 5d><% 6d><% 6d>", 1337, -1337, 1337, -1337, 1337, -1337));

	printf(" %d\n", ft_printf("<%- 4d><%- 4d><%- 5d><%- 5d><%- 6d><%- 6d>", 1337, -1337, 1337, -1337, 1337, -1337));
	printf(" %d\n\n", printf("<%- 4d><%- 4d><%- 5d><%- 5d><%- 6d><%- 6d>", 1337, -1337, 1337, -1337, 1337, -1337));
	//*/
	return (0);
}
