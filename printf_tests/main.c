/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:23:02 by ablin             #+#    #+#             */
/*   Updated: 2018/08/25 21:28:23 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_test.h"

int		main()
{
//	TO RUN ONE BY ONE

//	conv_tests();
//	width_tests();
//	preci_tests();
//	length_mod_tests();
//	mix_tests();
//	ub_tests();
//	random_tests();
	
	printf("MB_CUR_MAX: %d\n", MB_CUR_MAX);
	printf(" %d\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, UINT_MAX));
	printf(" %d\n\n", printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));

	printf(" %d\n", ft_printf("%C", 254));
	printf(" %d\n\n", ft_printf("%C", 254));
	
	setlocale(LC_ALL, "");

	printf("MB_CUR_MAX: %d\n", MB_CUR_MAX);
	printf(" %d\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, UINT_MAX));
	printf(" %d\n\n", printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));

	printf(" %d\n", ft_printf("%C", 254));
	printf(" %d\n\n", ft_printf("%C", 254));

	return (0);
}
