/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:00:29 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:00:31 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putc(char c)
{
	counter(0);
	write(1, &c, 1);
}

void		ft_putnc(char c, int n)
{
	if (n < 0)
		n = 0;
	while (n--)
		ft_putc(c);
}

void		ft_puts(char *str)
{
	if (!str)
		return ;
	while (*str)
		ft_putc(*str++);
}

void		ft_put_str(char *str, t_printf pf)
{
	if (!str)
		str = "(null)";
	pf.width -= ft_min(ft_strlen(str), pf.precision);
	!pf.moins ? ft_putwidth(pf.width, pf) : 1;
	if (pf.precision > 0 || pf.precision == -1)
	{
		while (*str && (pf.precision || pf.precision == -1))
		{
			ft_putc(*str++);
			pf.precision--;
		}
	}
	pf.moins ? ft_putwidth(pf.width, pf) : 1;
}

void		ft_put_chr(char c, t_printf pf)
{
	!pf.moins ? ft_putwidth(pf.width - 1, pf) : 1;
	ft_putc(c);
	pf.moins ? ft_putwidth(pf.width - 1, pf) : 1;
}
