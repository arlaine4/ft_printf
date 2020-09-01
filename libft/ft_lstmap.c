/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:05:48 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:05:50 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*new;
	t_list			*tmp;
	t_list			*send;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	lst = lst->next;
	send = new;
	while (lst)
	{
		tmp = f(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		new = new->next;
		lst = lst->next;
	}
	return (send);
}
