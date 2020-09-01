/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:08:46 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:08:47 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrll(long long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbrll(-n);
	}
	else if (n >= 10)
	{
		ft_putnbrll(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}
