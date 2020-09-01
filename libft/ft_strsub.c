/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:12:53 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:12:56 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*new;
	int			i;

	if (s == NULL)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (len)
	{
		new[i] = s[start + i];
		i++;
		len--;
	}
	new[i] = '\0';
	return (new);
}
