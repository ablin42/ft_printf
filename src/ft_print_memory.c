#include "../includes/printf.h"

char		hex_digit(int v) 
{
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v;
}

int		ft_print_memory(void *p)
{
/*	ft_putulong((unsigned long)p);
	ft_putstr("\n");
	ft_putulong((unsigned int)p);
	ft_putstr("\n");
	ft_putulong((int)p);
	ft_putstr("\n");*/
	ft_putstr("0x");
	ft_putstr(ft_itoa_base_long((unsigned long)p, 16));
	return (0);
}

int		xzft_print_memory(void* p0) 
{
    int i;
    uintptr_t p = (uintptr_t)p0;

	ft_putstr("0x");
    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
        ft_putchar(hex_digit((p >> i) & 0xf));
    }
	return (0);
}

int		xxxprint_memory(const void *addr, size_t size)
{
    size_t printed = 0;
    size_t i;
    const unsigned char* pc = addr;
    for (i=0; i<size; ++i)
    {
        int  g;
        g = (*(pc+i) >> 4) & 0xf;
        g += g >= 10 ? 'a'-10 : '0';
        ft_putchar(g);
        printed++;
        g = *(pc+i) & 0xf;
        g += g >= 10 ? 'a'-10 : '0';
        ft_putchar(g);
        printed++;
        if (printed % 32 == 0)
			ft_putchar('\n');
        else if (printed % 4 == 0)
			ft_putchar(' ');
    }
	return (0);
}
