#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <stdlib.h>

# define SPEC(Value) (((Value == ' ' || Value == '#' || Value == '*' || Value == '+' || Value == '-' || Value == '.' || Value == 'l' || Value == 'j' || Value == 'h' || Value == 'z') || (Value >= '0' && Value <= '9')) && Value != '\0')

# define FLAG_EXC lst->flag != 'o' && lst->flag != 'O' && lst->flag != 'x' && lst->flag != 'X' && lst->flag != 'u' && lst->flag != 'p'

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

//fill_list.c
t_arg	*add_arg(t_arg *lst, char flag, char *wflag);
t_arg	*add_str(t_arg *lst, char *format, char *str);
void	fetch_arg(t_arg **lst, const char *restrict format);

//padding.c
int		blank_and_sign(t_arg *lst, uintmax_t size, int signe, int toprint);
int		precision_and_zero(t_arg *lst, uintmax_t size, int signe);
void	minus_flag(t_arg *lst, int toprint);

//precision.c
int		htag(t_arg *lst, int signe, int mode);
int		str_handler(t_arg *lst, va_list ap);

//length_handler.c
intmax_t	handle_length(t_arg *lst, va_list ap);
uintmax_t	handle_ulength(t_arg *lst, va_list ap);

//utils.c
int		is_there(char *wflag, char c);
int		is_flag_zero(char *wflag);
int		get_pad(char *str);
int		get_preci(char *str);

//utils2.c
int		divide_nb(intmax_t nb, int divider);
int		divide_unb(uintmax_t nb, int base);
int		to_print(char c, int toprint);
void	to_print_s(int toprint, char *wflag);
int		wchar_len(wchar_t c);

//char_handler.c
int		ft_putwstr_preci(wchar_t *str, char *wflag);
int		c_padding(t_arg *lst, va_list ap);
int		print_wstr(t_arg *lst, va_list ap);
int		print_wchar(t_arg *lst, va_list ap);
int		str_noflag(t_arg *lst, va_list ap);

//nb_handler.c
int		int_handler(t_arg *lst, va_list ap);
int		hex_handler(t_arg *lst, va_list ap);

#endif
