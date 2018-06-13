#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

# define SPEC(Value) (Value != 'c' && Value != 'C' && Value != 'd' && Value != 'D' && Value != 'e'\
&& Value != 'f' && Value != 'i' && Value != 'o' && Value != 'O' && Value != 's' && Value != 'S'\
&& Value != 'u' && Value != 'U' && Value != 'x' && Value != 'X' && Value != '%')

typedef union	u_type
{
	int				d;
	long long		D;
	char			c;
	char			*str;
	int				*S;
	unsigned int	x;
	int				o;
	double			f;
	//long long		l;
	unsigned long long U;
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

int		ft_printf(const char * restrict format, ...);
void	test(t_arg *lst, int *retour);
void	test2(t_arg *lst, int *retour);

//fill_list.c
t_arg	*add_type_arg(t_arg *lst, char flag, char *wflag, int id);
t_arg	*add_string_noarg(t_arg *lst, char *format, int start, int end, int id);
void	lst_type_arg(t_arg **lst, const char *restrict format);
t_arg	*cycle_arg(t_arg *lst, va_list ap);

//hex_oct_handler.c
int		hex_oct_handler(char *wflag, unsigned int nb, char flag);
int		octal_handler(char *wflag, unsigned int nb, char flag);
int		O_handler(char *wflag, unsigned long nb, char flag);

//nb_padding.c
int		nb_padding_data(char *wflag, int nb);
int		count_printed_nb(char *wflag, int nb);
int		nb_padding_data(char *wflag, int nb);
int		leftjustify(char *wflag, int nb);
int		leftjustifyblank(char *wflag, int nb);

//precision.c
int		flag_and_precision(char *wflag, int nb);
int		str_precision(char *wflag, int nb);
char	*str_precisionx(char *wflag, char *str);
int		str_padding(char *wflag, char *str);
int		int_precision(char *wflag, int nb);

//print_format.c
int		ft_putlonglong(long long n);
int		ft_putulong(unsigned long long n);

//utils.c
int		is_there(char *wflag, char c);
int		is_flag_zero(char *wflag);
int		atoi_wflag(const char *str);
int		atoi_precision(const char *str);

//utils2.c
int		divide_nb(int nb, int divider);
int		to_print(char c, int toprint);
int		divide_ll(long long n);

//ft_hex_to_bin.c
int		bin_to_hex(char *bin);


#endif
