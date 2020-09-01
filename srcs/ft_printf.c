/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:01:20 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:01:22 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putwidth(int len, t_printf pf)
{
	if (pf.space || pf.plus)
		pf.width--;
	if (pf.zero && pf.moins && len > 0)
		ft_putnc(' ', len);
	else if (pf.zero && len > 0)
		ft_putnc('0', len);
	else if (len > 0)
		ft_putnc(' ', len);
	pf.width = 0;
}

void		ft_printer(char **format, va_list arg)
{
	t_printf		pf;

	pf = parsing_flags(format);
	if (pf.convertion < 0)
		return ;
	if (pf.convertion == 0 || pf.convertion == 1)
		ft_putnbr_int(conv_di_modifier(arg, pf), pf);
	if (pf.convertion == 2)
		ft_putnbr_octal(conv_oux_modifier(arg, pf), pf);
	if (pf.convertion == 3)
		ft_putnbr_unsigned(conv_oux_modifier(arg, pf), pf);
	if (pf.convertion == 4)
		ft_putnbr_hex(conv_oux_modifier(arg, pf), pf);
	if (pf.convertion == 5)
		ft_putnbr_hex(conv_oux_modifier(arg, pf), pf);
	if (pf.convertion == 6)
		ft_put_chr(conv_di_modifier(arg, pf), pf);
	if (pf.convertion == 7)
		ft_put_str(va_arg(arg, char *), pf);
	if (pf.convertion == 8)
		ft_putnbr_address(va_arg(arg, void *), pf);
	if (pf.convertion == 9)
		ft_putnbr_float(conv_f_modifier(arg, pf), pf);
	if (pf.convertion == 10)
		undefined_flag(pf);
}

void		undefined_flag(t_printf pf)
{
	!pf.moins ? ft_putwidth(pf.width - 1, pf) : 1;
	ft_putc('%');
	pf.moins ? ft_putwidth(pf.width - 1, pf) : 1;
}

int			ft_printf(char *format, ...)
{
	va_list		arg;

	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_printer(&format, arg);
		}
		else
			ft_putc(*format++);
	}
	va_end(arg);
	return (counter(1));
}
