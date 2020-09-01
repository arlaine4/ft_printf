/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:11:42 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:11:44 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
		n--;
	}
	return (1);
}
