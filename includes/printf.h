#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

//# define SPEC(Value) (Value != 'c' && Value != 'C' && Value != 'd' && Value != 'D' && Value != 'e'\
&& Value != 'f' && Value != 'i' && Value != 'o' && Value != 'O' && Value != 's' && Value != 'S'\
&& Value != 'u' && Value != 'U' && Value != 'x' && Value != 'X' && Value != 'p' && Value != '%')

//# define SPEC(Value) (((Value >= 0 && Value < 65) || (Value > 90 && Value < 97) || Value > 122) && Value != '%' && Value != '\0')

# define SPEC(Value) (((Value == ' ' || Value == '#' || Value == '*' || Value == '+' || Value == '-' || Value == '.' || Value == 'l' || Value == 'j' || Value == 'h' || Value == 'z') || (Value >= '0' && Value <= '9')) && Value != '\0')

//condition for %
typedef union	u_type
{
	long long int				d;
	long long		D;
	char			c;
	char			*str;
	int				*S;
	unsigned int	x;
	unsigned long	*p;
	int				o;////
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
t_arg	*add_type_arg(t_arg *lst, char flag, char *wflag);
t_arg	*add_string_noarg(t_arg *lst, char *format, int start, int end);
void	lst_type_arg(t_arg **lst, const char *restrict format);
t_arg	*cycle_arg(t_arg *lst, va_list ap);

//padding.c
int		padding(char *wflag, long long int nb, int base, char flag);
int		blank_and_sign(char *wflag, char flag, long long int nb, int toprint);
int		precision_and_zero(char *wflag, long long int nb, int base, char flag);

//precision.c
int		hashtag_handler(char *wflag, char flag, long long int nb, int mode);
int		str_handler(char *wflag, char *str);

//print_format.c
int		ft_putlonglong(long long n);
int		ft_putulong(unsigned long long n);

//utils.c
int		is_there(char *wflag, char c);
int		is_flag_zero(char *wflag);
int		atoi_wflag(const char *str);
int		atoi_precision(const char *str);

//utils2.c
int		divide_nb(long long nb, int divider);
int		to_print(char c, int toprint);
void	to_print_s(int toprint, char *wflag);
int		divide_ll(long long n);
int		divide_ull(unsigned long long n, int base);
int		wchar_len(wchar_t c);

//extra_padding.c
int		c_padding(char *wflag, char c);
int		ft_putwstr_preci(wchar_t *str, char *wflag);
int		print_wstr(char *wflag, wchar_t *S);
int		print_wchar(char *wflag, wchar_t c);

#endif
