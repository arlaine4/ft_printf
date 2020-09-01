/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:00:56 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:00:58 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*g_tab_base = "0123456789ABCDEF";

char	*ft_reverse_nbr(char *nbr)
{
	char	*ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(ret = ft_strnew(ft_strlen(nbr) + 1)))
		return (NULL);
	while (nbr[j])
		j++;
	j--;
	while (j >= 0)
		ret[i++] = nbr[j--];
	return (ret);
}

char	*ft_lltoa(long long n)
{
	long long		nbr;
	char			ret[100];
	int				i;

	if (n > 9223372036854775807 || n < -9223372036854775807)
		return (ft_lltoa_base(n, 10));
	i = 0;
	nbr = n < 0 ? -n : n;
	while (nbr || !i)
	{
		ret[i++] = '0' + nbr % 10;
		nbr = nbr / 10;
	}
	ret[i] = 0;
	return (ft_reverse_nbr(ret));
}

char	*ft_lltoa_base(unsigned long long n, size_t base)
{
	char	ret[100];
	int		i;

	i = 0;
	ft_bzero(ret, 100);
	while (n || !i)
	{
		ret[i++] = g_tab_base[n % base];
		n = n / base;
	}
	ret[i] = 0;
	return (ft_reverse_nbr(ret));
}

int		pf_ft_atoi(char *str)
{
	int		ret;

	ret = 0;
	while (*str && *str <= '9' && *str >= '0')
	{
		ret = ret * 10 + (*str % '0');
		str++;
	}
	return (ret);
}
