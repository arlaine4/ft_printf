/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:02:03 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:02:05 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define MOD_L  1
# define MOD_LL 2
# define MOD_H  3
# define MOD_HH 4

# define CONVERTER "diouxXcspf%"
# define FLAGS "# 0+-"

typedef struct		s_printf
{
	int				sharp;
	int				zero;
	int				space;
	int				plus;
	int				moins;
	int				width;
	int				precision;
	int				modifier;
	int				convertion;
}					t_printf;

int					ft_printf(char *format, ...);
char				*ft_lltoa(long long n);
char				*ft_lltoa_base(unsigned long long n, size_t base);
void				ft_putc(char c);
void				ft_putnc(char c, int n);
void				ft_puts(char *str);
int					ft_min(int a, int b);
void				ft_put_str(char *str, t_printf pf);
void				ft_putnbr_float(long double n, t_printf pf);
void				ft_putnbr_int(long long n, t_printf pf);
void				ft_putnbr_octal(long long n, t_printf pf);
void				ft_putnbr_hex(long long n, t_printf pf);
void				ft_putnbr_unsigned(unsigned long long n, t_printf pf);
void				ft_putnbr_address(void *address, t_printf pf);
void				ft_put_chr(char c, t_printf pf);
void				undefined_flag(t_printf pf);
void				ft_putwidth(int len, t_printf pf);
char				*to_lower(char *str);
int					pf_ft_atoi(char *str);
int					is_in(char *str, char c);
void				pf_initialize(t_printf *pf);
int					ft_index(char *str, char c);
t_printf			parsing_flags(char **format);
t_printf			parsing_width(char **format, t_printf pf);
t_printf			parsing_precision(char **format, t_printf pf);
t_printf			parsing_modifier(char **format, t_printf pf);
t_printf			parsing_convertion(char **format, t_printf pf);
long long			conv_oux_modifier(va_list arg, t_printf pf);
long long			conv_di_modifier(va_list arg, t_printf pf);
long double			conv_f_modifier(va_list arg, t_printf pf);
int					counter(int x);
long double			ft_round(long double n, int precision);

#endif
