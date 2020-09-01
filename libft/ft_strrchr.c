/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:12:07 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:12:09 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*new;

	i = 0;
	new = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			new = (((char *)s + i));
		i++;
		if (s[i] == (unsigned char)c)
			new = (((char *)s + i));
	}
	return (new);
}
