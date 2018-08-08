/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:20:58 by ablin             #+#    #+#             */
/*   Updated: 2017/11/30 23:37:54 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libfunc.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s != NULL && s != 0 && s[i] != '\0')
		i++;
	return (i);
}
