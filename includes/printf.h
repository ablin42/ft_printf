#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>

# define SPEC(Value) (Value != 'c' && Value != 'd' && Value != 'e'\
&& Value != 'f' && Value != 'i' && Value != 'o' && Value != 's'\
&& Value != 'u' && Value != 'x' && Value != '%')//condition for %%

typedef union	u_type
{
	int			d;
	char		c;
	char		*str;
	double		f;
	long long	l;
	unsigned long long z;
}				t_type;

typedef struct	s_arg
{
	int			id;
	char		*wflag; //change name?
	char		flag;
	int			width;
	int			precision;
	char		length;
	char		conv;
	t_type		type;
	struct		s_arg *next;
}				t_arg;

void	test(t_arg *lst, int *retour);
void	test2(t_arg *lst, int *retour);


int		ft_atoi_precision(const char *str);

char	*ft_strprecision(char *wflag, char *str);

int		is_there(char *wflag, char c);
int		is_flag_zero(char *wflag);
int		ft_atoi_wflag(const char *str);

int		ft_divide_nb(int nb, int divider);
int		to_print(char c, int toprint);

int		count_flags(const char * restrict format);
int		ft_printf(const char * restrict format, ...);
#endif
