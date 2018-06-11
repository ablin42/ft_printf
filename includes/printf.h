#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

# define SPEC(Value) (Value != 'c' && Value != 'C' && Value != 'd' && Value != 'e'\
&& Value != 'f' && Value != 'i' && Value != 'o' && Value != 's'\
&& Value != 'u' && Value != 'x' && Value != 'X' && Value != '%')

typedef union	u_type
{
	int				d;
	char			c;
	char			*str;
	unsigned int	x;
	int				o;
	double			f;
	long long		l;
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
void	ft_putlong(long long n);
void	ft_putulong(unsigned long long n);

//utils.c
int		is_there(char *wflag, char c);
int		is_flag_zero(char *wflag);
int		atoi_wflag(const char *str);
int		atoi_precision(const char *str);

//utils2.c
int		divide_nb(int nb, int divider);
int		to_print(char c, int toprint);

//ft_itoa_base.c
int		divide_nb_base(unsigned int nb, int base);
char	*ft_itoa_base(unsigned int n, int base);
char	*ft_itoa_base_up(unsigned int n, int base);

//ft_hex_to_bin.c
char	*ft_hex_to_bin(int hex);
int		bin_size(int hex);
int		print_wchar(int hex);
char	*apply_mask(char *bin, int hex);
int		bin_to_hex(char *bin);

int		ft_putwchar(wchar_t c);

#endif
