/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:23:02 by ablin             #+#    #+#             */
/*   Updated: 2018/08/22 03:48:55 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "main_test.h"
#include <wchar.h>

int		main()
{
int i;
i = 0;

//	conv_tests();
//	width_tests();
//	preci_tests();
//	length_mod_tests();
//	mix_tests();
//	ub_tests();
//	random_tests();
	
	printf(" %d\n", ft_printf("<%+-0 10.3o>", 256));
	printf(" %d\n\n", printf("<%+-0 10.3o>", 256));

	printf(" %d\n", ft_printf("%-8.3O", 0));
	printf(" %d\n\n", printf("%-8.3O", 0));
	
	printf(" %d\n", ft_printf("%#.5O", 42));
	printf(" %d\n\n", ft_printf("%#.5O", 42));
	
	printf(" %d\n", ft_printf("%#.5o", 42));
	printf(" %d\n\n", ft_printf("%#.5o", 42));

	printf(" %d\n", ft_printf("%hX", (unsigned short)40));
	printf(" %d\n\n", printf("%hX", (unsigned short)40));
	
	printf(" %d\n", ft_printf("%#5.3x", 0x25));
	printf(" %d\n\n", printf("%#5.3x", 0x25));
	
	printf(" %d\n", ft_printf("%6.4O", 42));
	printf(" %d\n\n", printf("%6.4O", 42));
	
	printf(" %d\n", ft_printf("<%#15.4O>", 42));
	printf(" %d\n\n", printf("<%#15.4O>", 42));
	
	printf(" %d\n", ft_printf("<%#-8.3o>", 42));
	printf(" %d\n\n", printf("<%#-8.3o>", 42));
	
	printf(" %d\n", ft_printf("%#-8.3o", 0));
	printf(" %d\n\n", printf("%#-8.3o", 0));
	
	/*while (i == 0)
	{
		i = 0;
	}*/
	return (0);
}
