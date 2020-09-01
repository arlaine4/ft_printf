/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:00:45 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:00:47 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		counter(int x)
{
	static int		size = 0;
	int				tmp;

	if (x)
	{
		tmp = size;
		size = 0;
		return (tmp);
	}
	else
		return (size++);
}

int		ft_index(char *str, char c)
{
	int		i;

	if (c != 'X')
		c = ft_tolower(c);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

int		is_in(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	pf_initialize(t_printf *pf)
{
	pf->sharp = 0;
	pf->zero = 0;
	pf->space = 0;
	pf->plus = 0;
	pf->moins = 0;
	pf->width = 0;
	pf->precision = -1;
	pf->modifier = 0;
	pf->convertion = -1;
}

int		ft_min(int a, int b)
{
	if (a == -1)
		return (b);
	if (b == -1)
		return (a);
	if (a < b)
		return (a);
	return (b);
}
