#include "../includes/printf.h"

/*char	*apply_mask(char *bin, int hex)
{
//	char mask1[] = "0xxxxxxx";
//	char mask2[] = "110xxxxx10xxxxxx";
//	unsigned int mask2 = 49280;
//	char mask3[] = "1110xxxx10xxxxxx10xxxxxx";
//	char mask4[] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
//	char *mask;
	int		size;
//	unsigned char octet;
//	unsigned char octet2;
//	unsigned int v = hex;

	size = ft_strlen(bin);
	if (size <= 7)
		ft_putchar(hex);

	else if (size <= 11)
	{
		ft_putchar((hex >> 6) | 0xC0);
		ft_putchar((hex & 0x3F) | 0x80);
	}
	else if (size <= 11)
	{
		octet2 = (v << 26) >> 26;
		octet = ((v >> 6) << 27) >> 27;
		octet = (mask2 >> 8) | octet;
		ft_putchar(octet);
		octet = ((mask2 << 24) >> 24) | octet2;
		ft_putchar(octet);
	}
//	else if (size > 11 && size <= 16)

//	else (size > 16)

	return (bin);
}*/

char	*ft_hex_to_bin(int hex)
{
	char *bin;
	int i;
	int size;

	if (hex < 0)
		return (ft_strdup(""));
	i = 1;
	size = 0;
	while (i <= hex)
	{
		i <<= 1;
		size++;
	}
	if (size == 0)
		size = 1;
	if ((bin = ft_strnew(size)) == NULL)
		return (ft_strdup(""));
	if (hex == 0)
		bin[0] = '0';
	while (hex > 0)
	{
		bin[--size]= hex % 2 + '0';
		hex >>= 1;
	}
	return (bin);
}

int		print_wchar(int hex)
{
	int		retour;

	retour = 0;
	apply_mask(ft_hex_to_bin(hex), hex);
	return (retour);
}
