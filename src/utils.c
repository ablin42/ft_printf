int		is_there(char *wflag, char c)
{
	int		i;

	i = 0;
	while (wflag[i] != '\0')
	{
		if (wflag[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_atoi_wflag(const char *str)
{
	int i;
	int signe;
	int total;

	i = 0;
	signe = 1;
	total = 0;
	while (str[i] <= '0' || str[i] > '9')
	{//
		if (str[i] == '.')//
			return (0);//
		i++;
	}//
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total + str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9' && str[i + 1] != '\0')
			total = total * 10;
		i++;
	}
	return (total * signe);
}

int		ft_atoi_precision(const char *str)
{
	int i;
	int total;

	i = 0;
	total = 0;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (i - 1 < ft_strlen(str) || str[0] == '.')
		i++;
	//ft_putnbr(i);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		total = total + str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9' && str[i + 1] != '\0')
			total = total * 10;
		i++;
	}
	return (total);
}

int		is_flag_zero(char *wflag)
{
	int		i;

	i = 0;
	if (wflag[0] == '0')
		return (1);
	while (wflag[i] != '\0')
	{
		if (wflag[i] == '0' && i > 0 && (wflag[i - 1] < '0' || wflag[i - 1] > '9'))
			return (1);
			i++;
	}
	return (0);
}
