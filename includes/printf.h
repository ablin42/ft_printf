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
t_arg	*add_type_arg(t_arg *lst, char flag, char *wflag);
t_arg	*add_string_noarg(t_arg *lst, char *format, int start, int end);
void	lst_type_arg(t_arg **lst, const char *restrict format);
t_arg	*cycle_arg(t_arg *lst, va_list ap);

//padding.c
int		blank_and_sign(t_arg *lst, uintmax_t size, int signe, int toprint);
int		precision_and_zero(t_arg *lst, uintmax_t size, int signe);

//precision.c
int		htag(t_arg *lst, int signe, int mode);
int		str_handler(char *wflag, char *str);

//print_format.c obsolete
int		ft_putlonglong(long long n);//obsolete
int		ft_putulong(unsigned long long n);//obsolete

//length_handler.c
intmax_t	handle_length(t_arg *lst, va_list ap);
uintmax_t	handle_ulength(t_arg *lst, va_list ap);

//utils.c
int		is_there(char *wflag, char c);
int		is_flag_zero(char *wflag);
int		atoi_wflag(const char *str);
int		atoi_precision(const char *str);

//utils2.c
int		divide_nb(intmax_t nb, int divider);
int		to_print(char c, int toprint);
void	to_print_s(int toprint, char *wflag);
int		divide_unb(uintmax_t n, int base);
int		wchar_len(wchar_t c);

//extra_padding.c
//int		c_padding(char *wflag, char c);
int		ft_putwstr_preci(wchar_t *str, char *wflag);
//int		print_wstr(char *wflag, wchar_t *S);
//int		print_wchar(char *wflag, wchar_t c);

int		str_handler2(t_arg *lst, va_list ap);
int		int_handler(t_arg *lst, va_list ap);
int		hex_handler(t_arg *lst, va_list ap);
int		c_padding(t_arg *lst, va_list ap);
int		print_wstr(t_arg *lst, va_list ap);//wchar t wchar t*
int		print_wchar(t_arg *lst, va_list ap);
int		str_noflag(t_arg *lst, va_list ap);

#endif
