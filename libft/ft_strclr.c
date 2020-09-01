/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:09:36 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:09:37 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_strclr(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i])
		{
			s[i] = 0;
			i++;
		}
}
