/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:10:50 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:10:51 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	const char		*tmpsrc;
	char			*tmpdst;
	size_t			dsize;
	size_t			length;

	tmpsrc = src;
	tmpdst = dst;
	length = size;
	while (length-- && *tmpdst)
		tmpdst++;
	dsize = tmpdst - dst;
	length = size - dsize;
	if (!length)
		return (dsize + ft_strlen(src));
	while (*tmpsrc)
	{
		if (length != 1)
		{
			*tmpdst++ = *tmpsrc;
			length--;
		}
		tmpsrc++;
	}
	*tmpdst = '\0';
	return (dsize + (tmpsrc - src));
}
