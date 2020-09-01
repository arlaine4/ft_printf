/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:05:10 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:05:12 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		ft_initi(int *i, int *j, int *neg)
{
	*i = 0;
	*j = 0;
	*neg = 1;
}

char			*ft_itoll(long long n)
{
	char	ret[100];
	char	*r;
	int		neg;
	int		i;
	int		j;

	ft_initi(&i, &j, &neg);
	if (n < 0)
		neg = -1;
	while (neg * n > 9 || neg * n < 0)
	{
		ret[i] = '0' + neg * (n % 10);
		n = n / 10;
		i++;
	}
	ret[i++] = '0' + neg * n;
	if (neg < 0)
		ret[i++] = '-';
	if ((r = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	r[i] = '\0';
	while (i--)
		r[i] = ret[j++];
	return (r);
}
