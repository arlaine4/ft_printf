/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:11:59 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:12:01 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t		i;
	int			pos;
	int			len;

	i = 0;
	pos = 0;
	len = ft_strlen(s2);
	if (len == 0)
		return ((char *)s1);
	while (i < size && s1[i] != 0)
	{
		while (s2[pos] == s1[i + pos] && (i + pos) < size)
		{
			if (pos == len - 1)
				return ((char *)s1 + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
