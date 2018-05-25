/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_wflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:12:39 by ablin             #+#    #+#             */
/*   Updated: 2017/11/21 20:12:43 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_atoi_wflag(const char *str)
{
	int i;
	int signe;
	int total;

	i = 0;
	signe = 1;
	total = 0;
	while (str[i] <= '0' || str[i] > '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total + str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9' && str[i + 1] != '\0')
			total = total * 10;
		i++;
	}
	return (total * signe);
}
