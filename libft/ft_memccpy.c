/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:06:30 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:06:33 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;

	new_dest = (unsigned char *)dest;
	new_src = (unsigned char *)src;
	while (n)
	{
		*new_dest = *new_src;
		new_dest++;
		new_src++;
		n--;
		if (*(new_src - 1) == (unsigned char)c)
			return (new_dest);
	}
	return (0);
}
