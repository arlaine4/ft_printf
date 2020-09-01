/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:14:23 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:14:24 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int		ft_getline(char **line, char **new, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (new[fd][i] != '\n' && new[fd][i] != '\0')
		i++;
	if (i == 0 && (new[fd][i] == 0))
		return (0);
	if (new[fd][i] == '\n')
	{
		tmp = ft_strdup(new[fd] + i + 1);
		*line = ft_strnew(i + 1);
		ft_strncpy(*line, new[fd], i);
		ft_strdel(&new[fd]);
		new[fd] = tmp;
	}
	else
	{
		tmp = new[fd] + i;
		*line = ft_strnew(i + 1);
		ft_strncpy(*line, new[fd], i);
		ft_strdel(&new[fd]);
		new[fd] = tmp;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*new[10240];
	char			*tmp;
	int				rea;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0 || fd > 10240 ||
		BUFF_SIZE <= 0)
		return (-1);
	while ((rea = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (new[fd] == 0)
			new[fd] = ft_strnew(1);
		buff[rea] = '\0';
		tmp = ft_strjoin(new[fd], buff);
		ft_strdel(&new[fd]);
		new[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ft_getline(line, new, fd) == 1)
		return (1);
	else
		return (0);
}
