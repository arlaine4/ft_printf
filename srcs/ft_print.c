/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:01:13 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:01:15 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_int(long long n, t_printf pf)
{
	char	*nbr;
	int		prec;

	if (n >= 0 && (pf.plus || pf.space))
		pf.width--;
	nbr = ft_lltoa(n);
	!n && !pf.precision ? pf.width++ : 1;
	prec = pf.precision < 0 ? 0 : pf.precision - ft_strlen(nbr);
	prec = prec < 0 ? 0 : prec;
	pf.width = n < 0 ? pf.width - 1 : pf.width;
	(n < 0 && pf.zero) ? ft_putc('-') : 0;
	pf.width -= ft_strlen(nbr);
	if (n >= 0 && (pf.plus || pf.space) && (pf.width - prec > 0 && pf.zero))
		pf.plus ? ft_putc('+') : ft_putc(' ');
	!pf.moins ? ft_putwidth(pf.width - prec, pf) : 1;
	if (n >= 0 && (pf.plus || pf.space) && !(pf.width - prec > 0 && pf.zero))
		pf.plus ? ft_putc('+') : ft_putc(' ');
	(n < 0 && !pf.zero) ? ft_putc('-') : 0;
	ft_putnc('0', pf.precision - (int)ft_strlen(nbr));
	if (n == 0)
		pf.precision ? ft_puts(nbr) : 0;
	else
		ft_puts(nbr);
	pf.moins ? ft_putwidth(pf.width - prec, pf) : 0;
	free(nbr);
}

void	ft_putnbr_octal(long long n, t_printf pf)
{
	char	*nbr;
	int		precision;

	nbr = ft_lltoa_base(n, 8);
	if (!pf.precision && !n)
		pf.width++;
	precision = pf.precision < 0 ? 0 : pf.precision - ft_strlen(nbr);
	precision = precision < 0 ? 0 : precision;
	pf.width = n < 0 ? pf.width - 1 : pf.width;
	pf.width -= ft_strlen(nbr);
	pf.sharp && n && !precision ? pf.width-- : 1;
	!pf.moins && !pf.zero ? ft_putwidth(pf.width - precision, pf) : 1;
	if (pf.sharp && (n || precision || !pf.precision))
		ft_putc('0');
	!pf.moins && pf.zero ? ft_putwidth(pf.width - precision, pf) : 1;
	ft_putnc('0', pf.precision - (int)ft_strlen(nbr) - pf.sharp);
	if (pf.precision == 0 && n == 0)
		pf.width += 1;
	else
		ft_puts(nbr);
	pf.moins ? ft_putwidth(pf.width - precision, pf) : 0;
	free(nbr);
}

void	ft_putnbr_address(void *address, t_printf pf)
{
	char	*nbr;
	long	n;
	int		precision;

	n = (long)address > 0 ? (long)address : (unsigned int)address;
	nbr = ft_lltoa_base(n, 16);
	pf.width -= 2;
	precision = pf.precision - ft_strlen(nbr);
	precision = precision < 0 ? 0 : precision;
	!pf.moins ? ft_putwidth(pf.width - ft_strlen(nbr) - precision, pf) : 1;
	ft_puts("0x");
	ft_putnc('0', pf.precision - (int)ft_strlen(nbr));
	!n && !pf.precision ? 0 : ft_puts(to_lower(nbr));
	pf.moins == 1 ? ft_putwidth(pf.width - ft_strlen(nbr) - precision, pf) : 0;
	free(nbr);
}

void	ft_putnbr_hex(long long n, t_printf pf)
{
	char	*nbr;
	int		precision;

	nbr = ft_lltoa_base(n, 16);
	precision = pf.precision < 0 ? 0 : pf.precision - ft_strlen(nbr);
	precision = precision < 0 ? 0 : precision;
	pf.width = n < 0 ? pf.width - 1 : pf.width;
	pf.width -= !n && !pf.precision ? 0 : ft_strlen(nbr);
	pf.width = pf.sharp && n ? pf.width - 2 : pf.width;
	!pf.moins && !pf.zero ? ft_putwidth(pf.width - precision, pf) : 1;
	if (pf.sharp && n)
	{
		if (pf.convertion == 5)
			ft_puts("0X");
		if (pf.convertion == 4)
			ft_puts("0x");
	}
	!pf.moins && pf.zero ? ft_putwidth(pf.width - precision, pf) : 1;
	ft_putnc('0', pf.precision - (int)ft_strlen(nbr));
	if (!(pf.precision == 0 && n == 0))
		(pf.convertion == 5) ? ft_puts(nbr) : ft_puts(to_lower(nbr));
	pf.moins ? ft_putwidth(pf.width - precision, pf) : 0;
	free(nbr);
}

void	ft_putnbr_unsigned(unsigned long long n, t_printf pf)
{
	char	*nbr;
	int		precision;

	nbr = ft_lltoa_base(n, 10);
	precision = pf.precision < 0 ? 0 : pf.precision - ft_strlen(nbr);
	precision = precision < 0 ? 0 : precision;
	pf.width -= !n && !pf.precision ? 0 : ft_strlen(nbr);
	!pf.moins ? ft_putwidth(pf.width - precision, pf) : 1;
	ft_putnc('0', pf.precision - (int)ft_strlen(nbr));
	if (n == 0)
		pf.precision ? ft_puts(nbr) : 0;
	else
		ft_puts(nbr);
	pf.moins ? ft_putwidth(pf.width - precision, pf) : 0;
	free(nbr);
}
