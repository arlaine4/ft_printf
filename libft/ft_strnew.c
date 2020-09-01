/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:11:50 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:11:52 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	if (!(new = malloc(size + 1)))
		return (0);
	i = 0;
	while (i <= size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
