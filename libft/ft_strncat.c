/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:11:16 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:11:19 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		cpt;

	i = 0;
	cpt = 0;
	while (dest[cpt])
		cpt++;
	while (src[i] && i < n)
	{
		dest[cpt] = src[i];
		cpt++;
		i++;
	}
	dest[cpt] = '\0';
	return (dest);
}
