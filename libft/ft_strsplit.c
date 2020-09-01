/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:12:18 by arlaine           #+#    #+#             */
/*   Updated: 2019/03/03 16:12:19 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static int			count_words(char const *s, char c)
{
	int		count_words;

	count_words = 0;
	while (*s)
	{
		if ((*s != c && *(s - 1) == c) || (*s != c && *(s - 1) == '\0'))
		{
			count_words++;
		}
		s++;
	}
	return (count_words);
}

static int			*size_words(char const *s, char c)
{
	int		*size_words;
	int		i;
	int		words;
	int		index;

	words = count_words(s, c);
	if (!(size_words = malloc(sizeof(int) * words)))
		return (0);
	i = 0;
	while (i < words)
	{
		size_words[i] = 0;
		i++;
	}
	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
			size_words[index]++;
		else if (i > 0 && s[i - 1] != c)
			index++;
		i++;
	}
	return (size_words);
}

static void			ft_init(int *i, int *index, int *j)
{
	*i = -1;
	*index = 0;
	*j = 0;
}

static void			ft_init_2(char *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = *c + 1;
}

char				**ft_strsplit(char const *s, char c)
{
	char		**new;
	int			i;
	int			index;
	int			j;

	if (s == NULL)
		return (0);
	if (!(new = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	ft_init(&i, &index, &j);
	while (s[++i])
	{
		if (s[i] != c)
		{
			if (i == 0 || (s[i] != c && s[i - 1] == c))
				new[index] = ft_strnew(size_words(s, c)[index] * sizeof(char));
			new[index][j++] = s[i];
		}
		else if (i > 0 && s[i - 1] != c)
		{
			ft_init_2(&(new[index][j]), &j, &index);
		}
	}
	new[count_words(s, c)] = 0;
	return (new);
}
