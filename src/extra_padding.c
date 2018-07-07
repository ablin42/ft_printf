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
	if (is_flag_zero(wflag) && !is_there(wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
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
	if (is_flag_zero(wflag) && !is_there(wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(wflag, '-'))
		ft_putwchar(c);
	return (ret);
}

int		ft_putwstr_preci(wchar_t *str, char *wflag)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if ((str == NULL || str == 0) && !is_there(wflag, '.'))
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str != NULL && str[i] != '\0')
	{
		if (!is_there(wflag, '.') || (is_there(wflag, '.') &&
			ret + wchar_len(str[i]) <= atoi_precision(wflag)))
			ret += ft_putwchar(str[i]);
		i++;
	}
	return (ret);
}

int		print_wstr(char *wflag, wchar_t *S)
{
	int		toprint;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if ((S == NULL || S == 0) && !is_there(wflag, '.'))
		ret = 6;
	while (S != NULL && S[i] != '\0')// && (is_there(wflag, '.') && ret < atoi_precision(wflag)))
	{
		if (!is_there(wflag, '.') || (is_there(wflag, '.') &&
			ret + wchar_len(S[i]) <= atoi_precision(wflag)))
			ret += wchar_len(S[i]);
		i++;
	}
	toprint = atoi_wflag(wflag) - ret;
	if (toprint > 0)
		ret += toprint;
	if (is_there(wflag, '-'))// && (is_there(wflag, '.')))// && atoi_precision(wflag) != 0))
		ft_putwstr_preci(S, wflag);
	//	ft_putwstr(S);
	if (is_flag_zero(wflag))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(wflag, '-'))// && (is_there(wflag, '.') && atoi_precision(wflag) != 0))
		ft_putwstr_preci(S, wflag);
	//	ft_putwstr(S);
	return (ret);
}
