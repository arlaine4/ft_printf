/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:04:13 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:04:14 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

int		ft_fdline(char *to_open)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(to_open, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
	}
	return (i);
	close(fd);
}
