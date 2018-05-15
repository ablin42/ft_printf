#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>

typedef union u_type
{
	char	*str;
	char	c;
	int		u;
}				t_type;

typedef struct s_arg
{
	int		id;
	char	flag;
	t_type	type;
	struct s_arg *next;
}				t_arg;

void	test(t_arg *lst);
void	test2(t_arg *lst);
int		count_flags(const char * restrict format);
int		ft_printf(const char * restrict format, ...);
#endif
