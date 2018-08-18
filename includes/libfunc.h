#ifndef __LIBFUNC_H
# define __LIBFUNC_H
# include <string.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strtoupper(char *str);
char				*ft_itoa_base_u(uintmax_t n, int base);
void				pf_itoa_base(uintmax_t n, int base, char flag);
char				*ft_itoa_base(unsigned int n, int base);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_putwchar(wchar_t c);
int					ft_putwstr(wchar_t *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_toupper(int c);
#endif