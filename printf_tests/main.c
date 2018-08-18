/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:23:02 by ablin             #+#    #+#             */
/*   Updated: 2018/08/09 02:25:13 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "main_test.h"

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

	printf(" %d\n", ft_printf("%0#10.0x", 12345));
	printf(" %d\n\n", printf("%0#10.0x", 12345));

	/*printf(" %d\n", ft_printf("<%00+10.4d>", 0));
	printf(" %d\n\n", printf("<%00+10.4d>", 0));
	
	printf(" %d\n", ft_printf("<%00+10.4d>", 1234));
	printf(" %d\n\n", printf("<%00+10.4d>", 1234));

	printf(" %d\n", ft_printf("toto et %02u coco %-5lu mimi", 19, (unsigned long)-20));
	printf(" %d\n\n", printf("toto et %02u coco %-5lu mimi", 19, (unsigned long)-20));

	printf(" %d\n", ft_printf("%#-8.3o", 0));
	printf(" %d\n\n", printf("%#-8.3o", 0));
	
	printf(" %d\n", ft_printf("%#2o", 0));
	printf(" %d\n\n", printf("%#2o", 0));

	printf(" %d\n", ft_printf("%04.2o", 0));
	printf(" %d\n\n", printf("%04.2o", 0));
	
	printf(" %d\n", ft_printf("%#1.2o", 0));
	printf(" %d\n\n", printf("%#1.2o", 0));

	printf(" %d\n", ft_printf("%0#14.0oo", 12587499));
	printf(" %d\n\n", printf("%0#14.0oo", 12587499));
	
	printf(" %d\n", ft_printf("%#08x", 42));
	printf(" %d\n\n", printf("%#08x", 42));
	
	printf(" %d\n", ft_printf("%#8x", 42));
	printf(" %d\n\n", printf("%#8x", 42));

	printf(" %d\n", ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499));
	printf(" %d\n\n", printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499));*/
/*	
	printf(" %d u\n", ft_printf("<%u><%.u><%+-0 8.3u><%+#-0 8.3u>", 0, 0, 42, 42));
	printf(" %d u\n\n", printf("<%u><%.u><%+-0 8.3u><%+#-0 8.3u>", 0, 0, 42, 42));

	printf(" %d U\n", ft_printf("<%U><%.U><%+-0 8.3U><%+#-0 8.3U>", 0, 0, 42, 42));
	printf(" %d U\n\n", printf("<%U><%.U><%+-0 8.3U><%+#-0 8.3U>", 0, 0, 42, 42));
	
	printf(" %d o\n", ft_printf("<%o><%.o><%+-0 8.3o><%+#-0 8.3o>", 0, 0, 42, 42));
	printf(" %d o\n\n", printf("<%o><%.o><%+-0 8.3o><%+#-0 8.3o>", 0, 0, 42, 42));
	
	printf(" %d O\n", ft_printf("<%O><%.O><%+-0 8.3O><%+#-0 8.3O>", 0, 0, 42, 42));
	printf(" %d O\n\n", printf("<%O><%.O><%+-0 8.3O><%+#-0 8.3O>", 0, 0, 42, 42));
	
	printf(" %d x\n", ft_printf("<%x><%.x><%+-0 8.3x><%+#-0 8.3x>", 0, 0, 42, 42));
	printf(" %d x\n\n", printf("<%x><%.x><%+-0 8.3x><%+#-0 8.3x>", 0, 0, 42, 42));
	
	printf(" %d X\n", ft_printf("<%X><%.X><%+-0 8.3X><%+#-0 8.3X>", 0, 0, 42, 42));
	printf(" %d X\n\n", printf("<%X><%.X><%+-0 8.3X><%+#-0 8.3X>", 0, 0, 42, 42));
	
	printf(" %d p\n", ft_printf("<%p><%.p><%+-0 8.3p><%+#-0 8.3p>", 0, 0, 42, 42));
	printf(" %d p\n\n", printf("<%p><%.p><%+-0 8.3p><%+#-0 8.3p>", 0, 0, 42, 42));

	printf(" %d\n", ft_printf("<%#15.4O>", 42));
	printf(" %d\n\n", printf("<%#15.4O>", 42));
	
	printf(" %d\n", ft_printf("<%+#-0 8.3o>", 42));
	printf(" %d\n\n", printf("<%+#-0 8.3o>", 42));

	printf(" %d\n", ft_printf("<%+#-0 10.3o>", 256));
	printf(" %d\n\n", printf("<%+#-0 10.3o>", 256));

	printf(" %d\n", ft_printf("<%+++#-0 10.3o>", 1234567));
	printf(" %d\n\n", printf("<%+++#-0 10.3o>", 1234567));*/
	
/*	ft_printf("%s\\n", NULL);
	while (i == 0)
	{
		i = 0;
	}
*/	
	return (0);
}
