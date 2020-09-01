/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:00:37 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:00:39 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long		conv_di_modifier(va_list arg, t_printf pf)
{
	long long			nbr;

	if (pf.modifier == 0)
		nbr = va_arg(arg, int);
	if (pf.modifier == MOD_L)
		nbr = va_arg(arg, long);
	if (pf.modifier == MOD_LL)
		nbr = va_arg(arg, long long);
	if (pf.modifier == MOD_H)
		nbr = (short int)va_arg(arg, int);
	if (pf.modifier == MOD_HH)
		nbr = (char)va_arg(arg, int);
	return (nbr);
}

long long		conv_oux_modifier(va_list arg, t_printf pf)
{
	long long			nbr;

	if (pf.modifier == 0)
		nbr = va_arg(arg, unsigned int);
	if (pf.modifier == MOD_L)
		nbr = va_arg(arg, unsigned long);
	if (pf.modifier == MOD_LL)
		nbr = va_arg(arg, unsigned long long);
	if (pf.modifier == MOD_H)
		nbr = (short unsigned int)va_arg(arg, int);
	if (pf.modifier == MOD_HH)
		nbr = (unsigned char)va_arg(arg, int);
	return (nbr);
}

long double		conv_f_modifier(va_list arg, t_printf pf)
{
	long double		nbr;

	if (pf.modifier == MOD_L)
		nbr = ft_round(va_arg(arg, long double), pf.precision);
	else
		nbr = ft_round(va_arg(arg, double), pf.precision);
	return (nbr);
}
