/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 04:18:39 by ablin             #+#    #+#             */
/*   Updated: 2017/12/02 06:18:14 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libfunc.h"
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	if (s1 == NULL && s1 == 0)
	{
		dest = (char*)malloc(sizeof(*s1) * 7);
		dest = ft_strcpy(dest, "(null)");
		return (dest);
	}
	if ((dest = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1))) == NULL)// || s1 == NULL || s1 == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
