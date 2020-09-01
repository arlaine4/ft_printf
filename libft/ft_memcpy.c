/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:07:01 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:07:02 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*new_dest;
	char		*new_src;

	new_dest = (char *)dest;
	new_src = (char *)src;
	while (n)
	{
		*new_dest = *new_src;
		new_dest++;
		new_src++;
		n--;
	}
	return (dest);
}
