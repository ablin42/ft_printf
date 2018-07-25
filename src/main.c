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
	setlocale(LC_ALL, "en_US.UTF-8");
	char *str;
	
//	printf(" %d\n", ft_printf("<%hhd><%hd><%lld><%ld><%jd><%zd>", 1, 2, 3, 4, 5, 6));
//	printf(" %d\n", ft_printf("<%x><%x><%u><%u><%p>", 0, UINT_MAX, 0, UINT_MAX, &str));
//	printf(" %d\n\n", printf("<%x><%x><%u><%u><%p>", 0, UINT_MAX, 0, UINT_MAX, &str));
	
//	printf(" %d\n", ft_printf("<%D><%U>", LONG_MIN, ULONG_MAX));
//	printf(" %d\n\n", printf("<%D><%U>", LONG_MIN, ULONG_MAX));
	/*/ FLAG PLUS TESTS
//	printf(" %d\n", ft_printf("<%+C><%+o><%+o><%+O><%+O>", 0, 0, 42, 0, 0, 1));
//	printf(" %d\n\n", printf("<%+C><%+o><%+o><%+O><%+O>", 0, 0, 42, 0, 0, 1));
	
	printf(" %d\n", ft_printf("<%+s><% s><%.s><%s>", NULL, NULL, NULL, NULL));
	printf(" %d\n\n", printf("<%+s><% s><%.s><%s>", NULL, NULL, NULL, NULL));
	
	printf(" %d\n", ft_printf("<%+s><% s><%.s><%s>", 0, 0, 0, 0));
	printf(" %d\n\n", printf("<%+s><% s><%.s><%s>", 0, 0, 0, 0));
	
	printf(" %d\n", ft_printf("<%+s><% s><%.s><%s>", "", "", "", ""));
	printf(" %d\n\n", printf("<%+s><% s><%.s><%s>", "", "", "", ""));
	//*/

	/* UNDEFINED BEHAVIORS TESTS
	printf(" %d\n", ft_printf("<% d><% d><% i><% i>", 9999, -9999, 9999, -9999));
	printf(" %d\n\n", printf("<% d><% d><% i><% i>", 9999, -9999, 9999, -9999));

	//voir string et space u ici
	printf(" %d\n", ft_printf("<% u><% c><% c><% s><%s><%.s>", 9999, 0, 'a', NULL, NULL, NULL));
	printf(" %d\n\n", printf("<% u><% c><% c><% s><%s><%.s>", 9999, 0, 'a', NULL, NULL, NULL));
	
	printf(" %d\n", ft_printf("<% s><% s><% C><% C>< %S>", "(null)", "", 0, L'a', L""));
	printf(" %d\n\n", printf("<% s><% s><% C><% C>< %S>", "(null)", "", 0, L'a', L""));*/

/*
	int		i;
	char	c;
	char	*str;

	printf(" %d\n", ft_printf("<%p><%p><%p><%p><%p>", &i, &c, &str, &ft_strlen, 0));
	printf(" %d\n\n", printf("<%p><%p><%p><%p><%p>", &i, &c, &str, &ft_strlen, 0));
*/
//	printf(" %d\n", ft_printf("<%O><%O>", 42, LONG_MAX));
//	printf(" %d\n\n", printf("<%O><%O>", 42, LONG_MAX));

	//printf(" %d\n", ft_printf("<%U><%U><%U>", 0, 42, ULONG_MAX));
	//printf(" %d\n\n", printf("<%U><%U><%U>", 0, 42, ULONG_MAX));

	//printf(" %d\n", ft_printf("<%D><%D>", LONG_MIN, LONG_MAX));
	//printf(" %d\n\n", printf("<%D><%D>", LONG_MIN, LONG_MAX));
	
	//printf(" %d\n", ft_printf("<%D><%D><%D>", 42, -2147483648, 2147483647));
	//printf(" %d\n\n", printf("<%D><%D><%D>", 42, -2147483648, 2147483647));

//	printf(" %d\n", ft_printf("%o, %ho, %hho", -42, -42, -42));
//	printf(" %d\n\n", printf("%o, %ho, %hho", -42, -42, -42));
//	printf(" %d\n", ft_printf("{%s}{%s}", 0, ""));
//	printf(" %d\n\n", printf("{%s}{%s}", 0, ""));
	
	/*/ WIDE CHAR TESTS
	ft_printf("BASIC TESTS FOR WCHAR\n");
	printf(" %d\n", ft_printf("<--%C-->", L'\x0041'));
	printf(" %d\n\n", printf("<--%C-->", L'\x0041'));

	printf(" %d\n", ft_printf("<--%C-->", L'\x0470'));
	printf(" %d\n\n", printf("<--%C-->", L'\x0470'));

	printf(" %d\n", ft_printf("<--%C-->", L'\x277A'));
	printf(" %d\n\n", printf("<--%C-->", L'\x277A'));
	
	printf(" %d\n", ft_printf("<--%C-->", L'\x1F92E'));
	printf(" %d\n\n", printf("<--%C-->", L'\x1F92E'));
	//*/
	
	/*/ WIDE CHAR TESTS
	ft_printf("PRECISION TESTS FOR WCHAR\n");
	printf(" %d\n", ft_printf("<--%.C-->", L'\x0041'));
	printf(" %d\n\n", printf("<--%.C-->", L'\x0041'));

	printf(" %d\n", ft_printf("<--%.5C-->", L'\x0470'));
	printf(" %d\n\n", printf("<--%.5C-->", L'\x0470'));

	printf(" %d\n", ft_printf("<--%10.5C--><-%010.5C--><--%-10.5C--><--%-010.5C-->", L'\x277A', L'\x277A', L'\x277A', L'\x277A'));
	printf(" %d\n\n", printf("<--%10.5C--><-%010.5C--><--%-10.5C--><--%-010.5C-->", L'\x277A', L'\x277A', L'\x277A', L'\x277A'));
	
	printf(" %d\n", ft_printf("<--%5.10C-->", L'\x1F92E'));
	printf(" %d\n\n", printf("<--%5.10C-->", L'\x1F92E'));
	//*/

	/*/ WIDE STRING TESTS
	ft_printf("BASIC TESTS FOR WSTRING\n");
	printf(" %d\n", ft_printf("<%S>", NULL));
	printf(" %d\n\n", printf("<%S>", NULL));
	
	printf(" %d\n", ft_printf("<%S>", 0));
	printf(" %d\n\n", printf("<%S>", 0));

	printf(" %d\n", ft_printf("<--%S-->", L"flinguezmoi"));
	printf(" %d\n\n", printf("<--%S-->", L"flinguezmoi"));

	printf(" %d\n", ft_printf("<--%S-->", L"\x0041\x0470\x277A\x1F92E"));
	printf(" %d\n\n", printf("<--%S-->", L"\x0041\x0470\x277A\x1F92E"));
	
	printf(" %d\n", ft_printf("<--%S-->", L"flinguez \x1F92E  moi"));
	printf(" %d\n\n", printf("<--%S-->", L"flinguez \x1F92E  moi"));
	//*/
	
	/*/ WIDE STRING TESTS
	ft_printf("PRECISION TESTS FOR WSTRING\n");
	
	printf(" %d\n", ft_printf("%.4S", L"我是一只猫。"));
	printf(" %d\n\n", printf("%.4S", L"我是一只猫。"));
	
	printf(" %d\n", ft_printf("<--%015.5S-->", L"\x0041\x0470\x277A\x1F92E"));
	printf(" %d\n\n", printf("<--%015.5S-->", L"\x0041\x0470\x277A\x1F92E"));
	
	printf(" %d\n", ft_printf("<%.S><%.S><%.0S>", NULL, 0, 0));
	printf(" %d\n\n", printf("<%.S><%.S><%.0S>", NULL, 0, 0));
	
	printf(" %d\n", ft_printf("<--%.5S--><--%.15S>", L"flinguezmoi", L"flinguezmoi"));
	printf(" %d\n\n", printf("<--%.5S--><--%.15S>", L"flinguezmoi", L"flinguezmoi"));
	
	printf(" %d\n", ft_printf("<--%5.15S-->", L"flinguez \x1F92E  moi"));
	printf(" %d\n\n", printf("<--%5.15S-->", L"flinguez \x1F92E  moi"));
	//*/
	//
	/*/ UNSIGNED INT TESTS
	ft_printf("BASIC TESTS FOR UNSIGNED INT\n");
	printf(" %d\n", ft_printf("<%u><%u><%lu>",  0, 42, 4294967295));
	printf(" %d\n\n", printf("<%u><%u><%lu>",  0, 42, 4294967295));
	
	printf(" %d\n\n", ft_printf("<%u><%u><%u>", -1, -2, -3));
	printf(" %d\n\n", printf("<%u><%u><%u>", -1, -2, -3));
	//*/

	/*/ OCTAL AND HEXADECIMAL TESTS
	ft_printf("BASIC TESTS FOR HEXADECIMAL AND OCTAL\n");
	printf(" %d\n", ft_printf("<%#x><%#x><%x><%#X><%X> ", 0, 13, 42, 255, 2147483647));
	printf(" %d\n\n", printf("<%#x><%#x><%x><%#X><%X> ", 0, 13, 42, 255, 2147483647));

	printf(" %d\n", ft_printf("<%o><%#o> ", 42, 1998));
	printf(" %d\n\n", printf("<%o><%#o> ", 42, 1998));
	//*/

	/*/ PRECISION TEST STR
	ft_printf("PRECISION TESTS FOR STRINGS\n");
	printf(" %d\n", ft_printf("<%.3s><%.3s><%.8s>", "Oof", "theater", "assassinate"));
	printf(" %d\n\n", printf("<%.3s><%.3s><%.8s>", "Oof", "theater", "assassinate"));
	
	printf(" %d\n\n", ft_printf("<%5.3s><%-5.3s><%13.8s>", "Oofballs", "theater", "assassinate"));
	printf(" %d\n\n", printf("<%5.3s><%-5.3s><%13.8s>", "Oofballs", "theater", "assassinate"));
	//*/

	/*/ PRECISION TESTS INT
	ft_printf("PRECISION TESTS FOR INT\n");
	printf(" %d\n", ft_printf("<%.d><%.0d><%5.d><%.d><%.0d>", 0, 0, 0, 42, 42));
	printf(" %d\n\n", printf("<%.d><%.0d><%5.d><%.d><%.0d>", 0, 0, 0, 42, 42));

	printf(" %d\n", ft_printf("<%-10.5d><%-6.3d><%-3.6d><%-5.10d>", 42, 42, -42, -42));
	printf(" %d\n\n", printf("<%-10.5d><%-6.3d><%-3.6d><%-5.10d>", 42, 42, -42, -42));
	
	printf(" %d\n", ft_printf("<%15.4d><%4.15d><%15.4d><%8.4d>", 424242, 424242424, -424242, -424242424));
	printf(" %d\n\n", printf("<%15.4d><%4.15d><%15.4d><%8.4d>", 424242, 424242424, -424242, -424242424));
	
	printf(" %d\n", ft_printf("<%.0d><%.1d><%.2d><%.2d><%.3d><%.3d>", 42, 42, 42, -42, 42, -42));
	printf(" %d\n\n", printf("<%.0d><%.1d><%.2d><%.2d><%.3d><%.3d>", 42, 42, 42, -42, 42, -42));

	printf(" %d\n", ft_printf("<%5.5d><%5.5d><%3.4d><%4.3d>", 13, -13, -13, 13));
	printf(" %d\n\n", printf("<%5.5d><%5.5d><%3.4d><%4.3d>", 13, -13, -13, 13));

	printf(" %d\n", ft_printf("<%-.5d><%5.5d><%10.5d>", 42, -42, -42));
	printf(" %d\n\n", printf("<%-.5d><%5.5d><%10.5d>", 42, -42, -42));
	//*/

	/*/ PRECISION TESTS UNSIGNED INT
	ft_printf("PRECISION TESTS FOR UNSIGNED INT\n");
	printf(" %d\n", ft_printf("<%.15u>", 2147483648));
	printf(" %d\n\n", printf("<%.15u>", 2147483648));

	printf(" %d\n", ft_printf("<%.u><%.0u><%.u><%.0u>", 0, 0, 42, 42));
	printf(" %d\n\n", printf("<%.u><%.0u><%.u><%.0u>", 0, 0, 42, 42));

	printf(" %d\n", ft_printf("<%-10.5d><%-6.3d><%-3.6d><%-5.10d>", 42, 42, -42, -42));
	printf(" %d\n\n", printf("<%-10.5d><%-6.3d><%-3.6d><%-5.10d>", 42, 42, -42, -42));
	
	printf(" %d\n", ft_printf("<%15.4u><%4.15u><%15.4u><%8.4u>", 424242, 424242424, 424242424, 77777));
	printf(" %d\n\n", printf("<%15.4u><%4.15u><%15.4u><%8.4u>", 424242, 424242424, 424242424, 77777));
	
	printf(" %d\n", ft_printf("<%.0u><%.1u><%.2u><%.2u><%.3u><%.3u>", 42, 42, 42, 133, 42, 133));
	printf(" %d\n\n", printf("<%.0u><%.1u><%.2u><%.2u><%.3u><%.3u>", 42, 42, 42, 133, 42, 133));

	printf(" %d\n", ft_printf("<%5.5u><%5.5u><%3.4u><%4.3u>", 13, 133, 133, 13));
	printf(" %d\n\n", printf("<%5.5u><%5.5u><%3.4u><%4.3u>", 13, 133, 133, 13));

	printf(" %d\n", ft_printf("<%-.5u><%5.5u><%10.5u>", 42, 422, 422));
	printf(" %d\n\n", printf("<%-.5u><%5.5u><%10.5u>", 42, 422, 422));
	//*/
	
	/*/ PRECISION TESTS OCTAL
	ft_printf("PRECISION TESTS FOR OCTAL\n");
	printf(" %d\n", ft_printf("<%#.4O><%#15.4O><%#4.15O><%#.0O>", 42, 42, 42, 0));
	printf(" %d\n\n", printf("<%#.4O><%#15.4O><%#4.15O><%#.0O>", 42, 42, 42, 0));
	
	printf(" %d\n", ft_printf("<%.4O><%15.4O><%4.15O><%.0O>", 42, 42, 42, 0));
	printf(" %d\n\n", printf("<%.4O><%15.4O><%4.15O><%.0O>", 42, 42, 42, 0));
	
	printf(" %d\n", ft_printf("<%.o><%.0o><%.o><%.0o>", 0, 0, 42, 42));
	printf(" %d\n\n", printf("<%.o><%.0o><%.o><%.0o>", 0, 0, 42, 42));

	printf(" %d\n", ft_printf("<%.4o><%.4o><%15.4o><%15.4o>", 42, 123456, 42, 123456));
	printf(" %d\n\n", printf("<%.4o><%.4o><%15.4o><%15.4o>", 42, 123456, 42, 123456));

	printf(" %d\n", ft_printf("<%8.4o><%4.15o><%4.15o><%4.8o>", 424242424, 42, 424242, 424242424));
	printf(" %d\n\n", printf("<%8.4o><%4.15o><%4.15o><%4.8o>", 424242424, 42, 424242, 424242424));
	
	printf(" %d\n", ft_printf("<%.0o><%.1o><%.2o><%.2o><%.3o><%.3o>", 42, 42, 42, 133, 42, 133));
	printf(" %d\n\n", printf("<%.0o><%.1o><%.2o><%.2o><%.3o><%.3o>", 42, 42, 42, 133, 42, 133));

	printf(" %d\n", ft_printf("<%-.5o><%5.5o><%10.5o>", 42, 422, 422));
	printf(" %d\n\n", printf("<%-.5o><%5.5o><%10.5o>", 42, 422, 422));
	//*/
	
	/*/ PRECISION TESTS HEXADECIMAL
	ft_printf("PRECISION TESTS FOR HEXADECIMAL\n");
	printf(" %d\n", ft_printf("<%.4X><%15.4X><%4.15X><%.0X>", 42, 42, 42, 0));
	printf(" %d\n\n", printf("<%.4X><%15.4X><%4.15X><%.0X>", 42, 42, 42, 0));
	
	printf(" %d\n", ft_printf("<%.x><%.0x><%.x><%.0x>", 0, 0, 42, 42));
	printf(" %d\n\n", printf("<%.x><%.0x><%.x><%.0x>", 0, 0, 42, 42));
	
	printf(" %d\n", ft_printf("<%.4x><%.4x><%15.4x><%15.4x>", 42, 123456, 42, 123456));
	printf(" %d\n\n", printf("<%.4x><%.4x><%15.4x><%15.4x>", 42, 123456, 42, 123456));

	printf(" %d\n", ft_printf("<%8.4x><%4.15x><%4.15x><%4.8x>", 424242424, 42, 424242, 424242424));
	printf(" %d\n\n", printf("<%8.4x><%4.15x><%4.15x><%4.8x>", 424242424, 42, 424242, 424242424));
	
	printf(" %d\n", ft_printf("<%.0x><%.1x><%.2x><%.2x><%.3x><%.3x>", 42, 42, 42, 133, 42, 133));
	printf(" %d\n\n", printf("<%.0x><%.1x><%.2x><%.2x><%.3x><%.3x>", 42, 42, 42, 133, 42, 133));

	printf(" %d\n", ft_printf("<%-.5x><%5.5x><%10.5x>", 42, 422, 422));
	printf(" %d\n\n", printf("<%-.5x><%5.5x><%10.5x>", 42, 422, 422));
	//*/

	//--------------------------WIDTH TESTS--------------------------//

	/*/ SIMPLE CHAR TESTS
	ft_printf("WIDTH TESTS FOR CHAR\n");
	printf(" %d\n", ft_printf("<%10c><%-3c><%05c><%-05c><%2c>", '4', '2', 'A', 'B', 0));
	printf(" %d\n\n", printf("<%10c><%-3c><%05c><%-05c><%2c>", '4', '2', 'A', 'B', 0));
	//*/
	
	/*/ WIDE CHAR TESTS
	ft_printf("WIDTH TESTS FOR WCHAR\n");
	printf(" %d\n", ft_printf("<--%10C-->", L'\x0041'));
	printf(" %d\n\n", printf("<--%10C-->", L'\x0041'));

	printf(" %d\n", ft_printf("<--%-10C-->", L'\x0470'));
	printf(" %d\n\n", printf("<--%-10C-->", L'\x0470'));

	printf(" %d\n", ft_printf("<--%010C-->", L'\x277A'));
	printf(" %d\n\n", printf("<--%010C-->", L'\x277A'));
	
	printf(" %d\n", ft_printf("<--%1C-->", L'\x1F92E'));
	printf(" %d\n\n", printf("<--%1C-->", L'\x1F92E'));
	//*/

	//*/ STR TESTS
	ft_printf("WIDTH TESTS FOR STRINGS\n");
	printf(" %d\n", ft_printf("{%-15Z}{%-15Ztr}{%10R}"));
	printf(" %d\n\n", printf("{%-15Z}{%-15Ztr}{%10R}{%05s}", "abc"));
	ft_putstr("{%-15Z}{%-15Ztr}{%10R}{%05abc}");
/*
	printf(" %d\n", ft_printf("<%10.5s><%5.10s><%10.10s>", "42", "98", "13"));
	printf(" %d\n\n", printf("<%10.5s><%5.10s><%10.10s>", "42", "98", "13"));

	printf(" %d\n", ft_printf("<%10.5s><%5.10s><%10.10s>", "123456", "123456"));
	printf(" %d\n\n", printf("<%10.5s><%5.10s><%10.10s>", "123456", "123456"));

	printf(" %d\n", ft_printf("<%10s><%010s><%-10s>", "Harbinger", "is their", "God."));
	printf(" %d\n\n", printf("<%10s><%010s><%-10s>", "Harbinger", "is their", "God."));
	
	printf(" %d\n", ft_printf("<%5s><%1s><%0-10s>", "Embrace", "", "entropy"));
	printf(" %d\n\n", printf("<%5s><%1s><%0-10s>", "Embrace", "", "entropy"));

	printf(" %d\n", ft_printf("<%-5s><%10s><%-3s>", "Death comes", "at last", "..."));
	printf(" %d\n\n", printf("<%-5s><%10s><%-3s>", "Death comes", "at last", "..."));
	
	printf(" %d\n", ft_printf("<This\tis\nan escape\\sequence.>"));
	printf(" %d\n\n", printf("<This\tis\nan escape\\sequence.>"));

	printf(" %d\n", ft_printf("<this %s is 100%% aids %%%%>", "shit"));
	printf(" %d\n\n", printf("<this %s is 100%% aids %%%%>", "shit"));*/
	//*/

	/*/ WIDE STRING TESTS
	ft_printf("WIDTH TESTS FOR WSTRINGS\n");
	printf(" %d\n", ft_printf("<%10S>", NULL));
	printf(" %d\n\n", printf("<%10S>", NULL));
	
	printf(" %d\n", ft_printf("<%-10S>", 0));
	printf(" %d\n\n", printf("<%-10S>", 0));

	printf(" %d\n", ft_printf("<--%15S-->", L"flinguezmoi"));
	printf(" %d\n\n", printf("<--%15S-->", L"flinguezmoi"));

	printf(" %d\n", ft_printf("<--%-25S-->", L"\x0041\x0470\x277A\x1F92E"));
	printf(" %d\n\n", printf("<--%-25S-->", L"\x0041\x0470\x277A\x1F92E"));
	
	printf(" %d\n", ft_printf("<--%025S-->", L"flinguez \x1F92E  moi"));
	printf(" %d\n\n", printf("<--%025S-->", L"flinguez \x1F92E  moi"));
	//*/
	
	/*/ INT TESTS
	ft_printf("WIDTH TESTS FOR INT\n");
	printf(" %d\n", ft_printf("<%10d><%4d><%30d><%10d>", 42, 10000, 10000, -42));
	printf(" %d\n\n", printf("<%10d><%4d><%30d><%10d>", 42, 10000, 10000, -42));

	printf(" %d\n", ft_printf("<%+---+3d><%--++3d>", 123, -123));
	printf(" %d\n\n", printf("<%+---+3d><%--++3d>", 123, -123));
	
	printf(" %d\n", ft_printf("<%3d><%4d><%3d>", 13, -42, -42));
	printf(" %d\n\n", printf("<%3d><%4d><%3d>", 13, -42, -42));

	printf(" %d\n", ft_printf("<%+5d><%+5d><%+5d><%-+5d><%-+5d><%-+5d>", 0, +0, -0, 0, +0, -0));
	printf(" %d\n\n", printf("<%+5d><%+5d><%+5d><%-+5d><%-+5d><%-+5d>", 0, +0, -0, 0, +0, -0));
	
	printf(" %d\n", ft_printf("<%+02d><%+02d><%+03d><%+03d><%+05d><%+05d><% 04d>", 42, -42, 42, -42, 42, -42, 42));
	printf(" %d\n\n", printf("<%+02d><%+02d><%+03d><%+03d><%+05d><%+05d><% 04d>", 42, -42, 42, -42, 42, -42, 42));

	printf(" %d\n", ft_printf("<%+4d><%+4d><%+5d><%+5d><%+6d><%+6d>", 1998, -1998, 1998, -1998, 1998, -1998));
	printf(" %d\n\n", printf("<%+4d><%+4d><%+5d><%+5d><%+6d><%+6d>", 1998, -1998, 1998, -1998, 1998, -1998));
	
	printf(" %d\n", ft_printf("<%+-4d><%+-4d><%+-5d><%+-5d><%+-6d><%+-6d>", 1998, -1998, 1998, -1998, 1998, -1998));
	printf(" %d\n\n", printf("<%+-4d><%+-4d><%+-5d><%+-5d><%+-6d><%+-6d>", 1998, -1998, 1998, -1998, 1998, -1998));
	
	printf(" %d\n", ft_printf("<% 4d><% 4d><% 5d><% 5d><% 6d><% 6d>", 1337, -1337, 1337, -1337, 1337, -1337));
	printf(" %d\n\n", printf("<% 4d><% 4d><% 5d><% 5d><% 6d><% 6d>", 1337, -1337, 1337, -1337, 1337, -1337));

	printf(" %d\n", ft_printf("<%- 4d><%- 4d><%- 5d><%- 5d><%- 6d><%- 6d>", 1337, -1337, 1337, -1337, 1337, -1337));
	printf(" %d\n\n", printf("<%- 4d><%- 4d><%- 5d><%- 5d><%- 6d><%- 6d>", 1337, -1337, 1337, -1337, 1337, -1337));
	//*/

	/*/ HEX TESTS
	ft_printf("WIDTH TESTS FOR HEXADECIMAL\n");
	printf(" %d\n", ft_printf("<%1x><%1X><%01x><%01X><%-1x><%-1X>", 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF));
	printf(" %d\n\n", printf("<%1x><%1X><%01x><%01X><%-1x><%-1X>", 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF));
	
	printf(" %d\n", ft_printf("<%030x><%30x><%-30x>", 0xFFFF, 0xFFFF, 0xFFFF));
	printf(" %d\n\n", printf("<%030x><%30x><%-30x>", 0xFFFF, 0xFFFF, 0xFFFF));

	printf(" %d\n", ft_printf("<%030X><%30X><%-30X>", 0xFFFF, 0xFFFF, 0xFFFF));
	printf(" %d\n\n", printf("<%030X><%30X><%-30X>", 0xFFFF, 0xFFFF, 0xFFFF));

	printf(" %d\n", ft_printf("<%#30X><%#30x><%#30x>", 0, 0, NULL));
	printf(" %d\n\n", printf("<%#30X><%#30x><%#30x>", 0, 0, NULL));
	
	printf(" %d\n", ft_printf("<%#030x><%#30x><%#-30x>", 0xFFFF, 0xFFFF, 0xFFFF));
	printf(" %d\n\n", printf("<%#030x><%#30x><%#-30x>", 0xFFFF, 0xFFFF, 0xFFFF));
	
	printf(" %d\n", ft_printf("<%#030X><%#30X><%#-30X>", 0xFFFF, 0xFFFF, 0xFFFF));
	printf(" %d\n\n", printf("<%#030X><%#30X><%#-30X>", 0xFFFF, 0xFFFF, 0xFFFF));
	//*/

	/*/ OCTAL TESTS
	ft_printf("WIDTH TESTS FOR OCTAL\n");
	printf(" %d\n", ft_printf("<%#.o><%#.0o><%#.x><%#.0x>", 0, 0, 0, 0));
	printf(" %d\n\n", printf("<%#.o><%#.0o><%#.x><%#.0x>", 0, 0, 0, 0));

	printf(" %d\n", ft_printf("<%#10x><%#10o><%#10o>", 0, 0, NULL));
	printf(" %d\n\n", printf("<%#10x><%#10o><%#10o>", 0, 0, NULL));

	printf(" %d\n", ft_printf("<%1o><%1O><%01o><%01O><%-1o><%-1O>", 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF));
	printf(" %d\n\n", printf("<%1o><%1O><%01o><%01O><%-1o><%-1O>", 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF));
	
	printf(" %d\n", ft_printf("<%5.10o><%15.10o><%-.10o>", 0xFFFF, 0xFFFF, 0xFFFF));
	printf(" %d\n\n", printf("<%5.10o><%15.10o><%-.10o>", 0xFFFF, 0xFFFF, 0xFFFF));
	
	printf(" %d\n", ft_printf("<%010o><%10o><%-10o>", 0xFFFF, 0xFFFF, 0xFFFF));
	printf(" %d\n\n", printf("<%010o><%10o><%-10o>", 0xFFFF, 0xFFFF, 0xFFFF));

	printf(" %d\n", ft_printf("<%010O><%10O><%-10O>", 0xFFFF, 0xFFFF, 0xFFFF));
	printf(" %d\n\n", printf("<%010O><%10O><%-10O>", 0xFFFF, 0xFFFF, 0xFFFF));
	
	printf(" %d\n", ft_printf("<%#010o><%#10o><%#-10o>", 0xFFFF, 0xFFFF, 0xFFFF));
	printf(" %d\n\n", printf("<%#010o><%#10o><%#-10o>", 0xFFFF, 0xFFFF, 0xFFFF));
	
	printf(" %d\n", ft_printf("<%#010O><%#10O><%#-10O>", 0xFFFF, 0xFFFF, 0xFFFF));
	printf(" %d\n\n", printf("<%#010O><%#10O><%#-10O>", 0xFFFF, 0xFFFF, 0xFFFF));
	//*/
	
	/*/ MEMORY ADDRESS TESTS
	ft_printf("WIDTH TESTS FOR MEMORY ADDRESS\n");
	printf(" %d\n", ft_printf("<%.0p><%.p><%.p><%.5p>", 0, 0, &ft_putnbr, 0));
	printf(" %d\n\n", printf("<%.0p><%.p><%.p><%.5p>", 0, 0, &ft_putnbr, 0));

	printf(" %d\n", ft_printf("<%2.9p><%2.9p><%9.2p><%2.9p>", 123456, 133, &ft_putnbr, &ft_putnbr));
	printf(" %d\n\n", printf("<%2.9p><%2.9p><%9.2p><%2.9p>", 123456, 133, &ft_putnbr, &ft_putnbr));
	
	printf(" %d\n", ft_printf("<%-33p><%025p><%-21p><%2p>", &ft_putchar, &ft_putnbr, &ft_itoa_base, &ft_putstr));
	printf(" %d\n\n", printf("<%-33p><%025p><%-21p><%2p>", &ft_putchar, &ft_putnbr, &ft_itoa_base, &ft_putstr));

	printf(" %d\n", ft_printf("<%5p><%-15p><%25p>", 0, 0, &ft_putnbr));
	printf(" %d\n\n", printf("<%5p><%-15p><%25p>", 0, 0, &ft_putnbr));
	//*/
	return (0);
}
