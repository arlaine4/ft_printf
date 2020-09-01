/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:07:39 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:07:40 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_power(int nb, int power)
{
	long long ret;

	if (power < 0)
		return (0);
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		ret = nb * ft_power(nb, power - 1);
	}
	return (ret);
}
