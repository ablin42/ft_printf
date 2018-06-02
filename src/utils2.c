/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 23:27:50 by ablin             #+#    #+#             */
/*   Updated: 2018/06/02 23:27:56 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_divide_nb(int nb, int divider)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb % divider)
	{
		nb /= divider;
		i++;
	}
	return (i);
}

int		to_print(char c, int toprint)
{
	while (toprint > 0)
	{
		ft_putchar(c);
		toprint--;
	}
	return (toprint);
}
