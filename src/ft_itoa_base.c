#include "../includes/printf.h"

char	*fillstr(int i, int n, int neg, char *str)
{
	while (i >= 1)
	{
		i--;
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

char		*ft_itoa_base(int n, int base)
{
	int		i;
	int		nb;
	int		neg;
	char	*str;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 1;
	nb = n;
	while (nb /= 10)
		i++;
	if (n < 0)
	{
		n = n * -1;
		i = i + 1;
		neg = 1;
	}
	if ((str = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	str[i] = '\0';
	return (fillstr(i, n, neg, str));
}
