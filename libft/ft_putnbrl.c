/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:08:40 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:08:41 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbrl(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbrl(-n);
	}
	else if (n >= 10)
	{
		ft_putnbrl(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}
