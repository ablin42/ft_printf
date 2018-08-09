#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "libfunc.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <stdlib.h>

# define SPEC(Value) (((Value == ' ' || Value == '#' || Value == '*' || Value == '+' || Value == '-' || Value == '.' || Value == 'l' || Value == 'j' || Value == 'h' || Value == 'z') || (Value >= '0' && Value <= '9')) && Value != '\0')

# define FLAG_EXC lst->flag != 'o' && lst->flag != 'O' && lst->flag != 'x' && lst->flag != 'X' && lst->flag != 'u' && lst->flag != 'U' && lst->flag != 'p'

typedef union	u_type
{
	char			c;
	char			*str;
}				t_type;

typedef enum	s_mod
{
	NONE = 0, HH = 1, H = 2, L = 3, LL = 4, J = 5, Z = 6
}				t_mod;

typedef struct	s_arg
{
	char		*wflag;
	char		flag;
	int			base;
	t_type		type;
	t_mod		mod;
	struct		s_arg *next;
}				t_arg;

typedef struct	s_fun
{
	char		*conv;
	void		(*handler)(t_arg *, va_list, int *);
}				t_fun;

//ft_printf.c
int			ft_printf(const char * restrict format, ...);
void		get_handler(t_arg *lst, va_list ap, int *retour);
void		cycle_arg(t_arg *lst, va_list ap, int *retour);
void		get_length_mod(t_arg *lst);

//fill_list.c
t_arg		*add_arg(t_arg *lst, char flag, char *wflag);
t_arg		*add_str(t_arg *lst, char *format, char *str);
void		fetch_arg(t_arg **lst, const char *restrict format);

//padding.c
int			blank_and_sign(t_arg *lst, uintmax_t size, int signe, int toprint);
int			precision_and_zero(t_arg *lst, uintmax_t size, int signe);
void		minus_flag(t_arg *lst, int toprint, int signe);

//length_handler.c
intmax_t	handle_length(t_arg *lst, va_list ap);
uintmax_t	handle_ulength(t_arg *lst, va_list ap);

//char_handler.c
void		c_padding(t_arg *lst, va_list ap, int *r);
int			putstr_exc(char *str, char *wflag);
void		str_handler(t_arg *lst, va_list ap, int *r);

//nb_handler.c
void		int_handler(t_arg *lst, va_list ap, int *r);
void		hex_handler(t_arg *lst, va_list ap, int *r);

//wide_char_handler.c
void		print_wchar(t_arg *lst, va_list ap, int *r);
void		print_wstr(t_arg *lst, va_list ap, int *r);
int			ft_putwstr_preci(wchar_t *str, char *wflag, int (*func)(wchar_t));

//utils.c
int			is_there(char *wflag, char c);
int			is_flag_zero(char *wflag);
int			get_pad(char *str);
int			get_preci(char *str);
int			htag(t_arg *lst, int signe, int mode);

//utils2.c
int			divide_nb(intmax_t nb, int divider, char *wflag);
int			divide_unb(uintmax_t nb, int base, char *wflag);
int			to_print(char c, int toprint);
void		to_print_s(int toprint, char *wflag);
int			wchar_len(wchar_t c);

#endif
