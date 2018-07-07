/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 23:26:08 by ablin             #+#    #+#             */
/*   Updated: 2018/06/02 23:27:03 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

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

int		atoi_wflag(const char *str)
{
	int		i;
	int		signe;
	int		total;

	i = 0;
	signe = 1;
	total = 0;
	if (str == NULL || ft_strcmp(str, "") == 0)
		return (0);
	while ((str[i] <= '0' || str[i] > '9') && str[i] != '\0')
	{
		if (str[i] == '.')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total + str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9' && str[i + 1] != '\0')
			total = total * 10;
		i++;
	}
	return (total * signe);
}

int		atoi_precision(const char *str)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (i - 1 < (int)ft_strlen(str) || str[0] == '.')
		i++;
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
		if (wflag[i] == '0' && i > 0 && (wflag[i - 1] < '0' ||
				wflag[i - 1] > '9'))
			return (1);
		i++;
	}
	return (0);
}
