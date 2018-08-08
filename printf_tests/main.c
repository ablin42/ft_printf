/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 01:23:37 by ablin             #+#    #+#             */
/*   Updated: 2018/07/08 01:23:38 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "main_test.h"

int		main()
{
int i;
i = 0;
	setlocale(LC_ALL, "en_US.UTF-8");////////voir macro mb_cur_max

//	conv_tests();
//	width_tests();
//	preci_tests();
//	length_mod_tests();
//	mix_tests();
	ub_tests();

/*	ft_printf("%s\\n", NULL);
//	while (i == 0)
//	{
//		i = 0;
//	}
*/	
	return (0);
}
