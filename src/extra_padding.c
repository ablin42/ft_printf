#include "../includes/printf.h"

int		c_padding(char *wflag, char c)
{
	int		toprint;
	int		ret;

	ret = atoi_wflag(wflag);
	if (ret == 0)
		ret = 1;
	toprint = ret - 1;
	if (is_there(wflag, '-'))
		ft_putchar(c);
	while (toprint > 0)
	{
		if (is_flag_zero(wflag) && !is_there(wflag, '-'))
			ft_putchar('0');
		else
			ft_putchar(' ');
		toprint--;
	}
	if (!is_there(wflag, '-'))
		ft_putchar(c);
	return (ret);
}

int		print_wchar(char *wflag, wchar_t c)
{
	int		toprint;
	int		ret;

	ret = wchar_len(c);
	toprint = atoi_wflag(wflag) - ret;
	if (toprint > 0)
		ret += toprint;
	if (is_there(wflag, '-'))
		ft_putwchar(c);
	if (is_flag_zero(wflag))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(wflag, '-'))
		ft_putwchar(c);
	return (ret);
}

int		print_wstr(char *wflag, wchar_t *S)
{
	int		toprint;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (S == NULL)
		ret = 6;
	while (S != NULL && S[i] != '\0')
	{
		ret += wchar_len(S[i]);
		i++;
	}
	toprint = atoi_wflag(wflag) - ret;
	if (toprint > 0)
		ret += toprint;
	if (is_there(wflag, '-'))
		ft_putwstr(S);
	if (is_flag_zero(wflag))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(wflag, '-'))
		ft_putwstr(S);
	return (ret);
}

int		hex_padding(char *wflag, char *nb, char *flag)
{
	int		retour;
	int		toprint;

	retour = ft_strlen(nb);
	if (is_there(wflag, '#') && (ft_strlen(nb) != 1 && nb[0] != 0)) //care segfault
		retour += 2;
	toprint = atoi_wflag(wflag) - retour;
	retour -= ft_strlen(nb);
	if (toprint > 0)
		retour += toprint;
	if ((is_flag_zero(wflag) || (toprint > 0 && is_there(wflag, '-'))
		|| is_there(wflag, '-')) && is_there(wflag, '#')
		&& (ft_strlen(nb) != 1 && nb[0] != 0))
		ft_putstr(flag);
	if (is_there(wflag, '-'))
		ft_putstr(nb);
	if (is_flag_zero(wflag))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(wflag, '-') && is_there(wflag, '#') && !is_flag_zero(wflag)
	&& (ft_strlen(nb) != 1 && nb[0] != 0))
		ft_putstr(flag);
	if (!is_there(wflag, '-'))
		ft_putstr(nb);
	return (retour);
}


















