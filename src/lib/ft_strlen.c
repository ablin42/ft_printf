/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:50:48 by ablin             #+#    #+#             */
/*   Updated: 2018/08/09 02:50:54 by ablin            ###   ########.fr       */
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
