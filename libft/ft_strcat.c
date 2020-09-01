/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:09:18 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:09:19 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (dest[cpt])
		cpt++;
	while (src[i])
	{
		dest[cpt] = src[i];
		cpt++;
		i++;
	}
	dest[cpt] = '\0';
	return (dest);
}
