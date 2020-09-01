/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:06:39 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:06:41 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new;

	new = (unsigned char *)s;
	while (n)
	{
		if (*new == (unsigned char)c)
			return (new);
		new++;
		n--;
	}
	return (0);
}
