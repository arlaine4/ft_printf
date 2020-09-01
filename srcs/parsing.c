/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:01:34 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:01:36 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_printf		parsing_flags(char **format)
{
	t_printf		pf;
	char			*tmp;

	tmp = *format;
	pf_initialize(&pf);
	while (*tmp && is_in(FLAGS, *tmp))
	{
		if (*tmp == '#')
			pf.sharp = 1;
		else if (*tmp == '0')
			pf.zero = 1;
		else if (*tmp == ' ')
			pf.space = 1;
		else if (*tmp == '+')
			pf.plus = 1;
		else if (*tmp == '-')
			pf.moins = 1;
		tmp++;
	}
	*format = tmp;
	return (parsing_width(format, pf));
}

t_printf		parsing_width(char **format, t_printf pf)
{
	pf.width = ft_atoi(*format);
	while (**format && ft_isdigit(**format))
		(*format)++;
	return (parsing_precision(format, pf));
}

t_printf		parsing_precision(char **format, t_printf pf)
{
	if (**format != '.')
		return (parsing_modifier(format, pf));
	(*format)++;
	pf.precision = pf_ft_atoi(*format);
	while (**format && ft_isdigit(**format))
		(*format)++;
	return (parsing_modifier(format, pf));
}

t_printf		parsing_modifier(char **format, t_printf pf)
{
	if (!(ft_strncmp(*format, "ll", 2)))
		pf.modifier = MOD_LL;
	else if (!(ft_strncmp(*format, "l", 1)) || !ft_strncmp(*format, "L", 1))
		pf.modifier = MOD_L;
	else if (!(ft_strncmp(*format, "hh", 2)))
		pf.modifier = MOD_HH;
	else if (!(ft_strncmp(*format, "h", 1)))
		pf.modifier = MOD_H;
	while (**format == 'h' || **format == 'l' || **format == 'L')
		(*format)++;
	return (parsing_convertion(format, pf));
}

t_printf		parsing_convertion(char **format, t_printf pf)
{
	if ((pf.convertion = ft_index(CONVERTER, **format)) >= 0)
		(*format)++;
	if (pf.convertion == 9 && pf.precision == -1)
		pf.precision = 6;
	if (pf.plus && pf.space)
		pf.space = 0;
	if (pf.zero && pf.moins)
		pf.zero = 0;
	if (pf.precision >= 0 && pf.zero && pf.convertion != 10)
		pf.zero = 0;
	return (pf);
}
