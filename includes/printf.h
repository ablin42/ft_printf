#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

//# define SPEC(Value) (Value != 'c' && Value != 'C' && Value != 'd' && Value != 'D' && Value != 'e'\
&& Value != 'f' && Value != 'i' && Value != 'o' && Value != 'O' && Value != 's' && Value != 'S'\
&& Value != 'u' && Value != 'U' && Value != 'x' && Value != 'X' && Value != 'p' && Value != '%')

# define SPEC(Value) (((Value == ' ' || Value == '#' || Value == '*' || Value == '+' || Value == '-' || Value == '.' || Value == 'l' || Value == 'j' || Value == 'h' || Value == 'z') || (Value >= '0' && Value <= '9')) && Value != '\0')

typedef union	u_type
{
	int				d;
	long long		D;
	char			c;
	char			*str;
	int				*S;
	unsigned int	x;
	unsigned long	*p;
	int				o;////
	unsigned long long U;
}				t_type;

typedef enum	s_mod
{
	NONE = 0, HH = 1, H = 2, L = 3, LL = 4, J = 5, Z = 6
}				t_mod;

typedef struct	s_arg
{
	int			id;
	char		*wflag;
	char		flag;
	int			base;
	t_type		type;
	t_mod		mod;
	struct		s_arg *next;
}				t_arg;

typedef struct	s_fun
{
	char		conv;
	int			(*handler)(t_arg *, va_list);
}				t_fun;

int		ft_printf(const char * restrict format, ...);
void	test(t_arg *lst, int *retour);
void	test2(t_arg *lst, int *retour);

//fill_list.c
t_arg	*add_type_arg(t_arg *lst, char flag, char *wflag, int id);
t_arg	*add_string_noarg(t_arg *lst, char *format, int start, int end, int id);
void	lst_type_arg(t_arg **lst, const char *restrict format);
t_arg	*cycle_arg(t_arg *lst, va_list ap);

//padding.c
int		padding(char *wflag, long long int nb, int base, char flag);
int		int_handler(t_arg *lst, va_list ap);
int		hex_handler(t_arg *lst, va_list ap);
int		blank_and_sign(char *wflag, char flag, long long int nb, int toprint);
int		precision_and_zero(char *wflag, long long int nb, int base, char flag);

//precision.c
int		hashtag_handler(char *wflag, char flag, long long int nb, int mode);
int		str_handler(char *wflag, char *str);
int		str_handler2(t_arg *lst, va_list ap);

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
int		divide_ll(long long n);
int		divide_ull(unsigned long long n, int base);
int		wchar_len(wchar_t c);

//extra_padding.c
int		c_padding(t_arg *lst, va_list ap);
int		ft_putwstr_preci(wchar_t *str, char *wflag);
int		print_wstr(t_arg *lst, va_list ap);//wchar t wchar t*
int		print_wchar(t_arg *lst, va_list ap);

#endif
