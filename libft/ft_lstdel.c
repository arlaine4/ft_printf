/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:05:23 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:05:25 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*new;
	t_list		*tmp;

	new = *alst;
	while (new)
	{
		tmp = new;
		new = new->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
	}
	*alst = NULL;
}
