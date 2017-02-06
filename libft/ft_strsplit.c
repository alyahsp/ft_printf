/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:59:47 by spalmaro          #+#    #+#             */
/*   Updated: 2016/11/07 18:38:50 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (s[i] == '\0' || !c)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if ((s[i] != c) && s[i])
		{
			while ((s[i] != c) && s[i])
				i++;
			words++;
		}
	}
	return (words);
}

static int	countletters(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] && (s[i] != c))
	{
		i++;
		j++;
	}
	return (j);
}

static void	fillarray(char *dst, const char *s, int *k, char c)
{
	int		i;
	int		j;

	i = 0;
	j = *k;
	while (s[j] && s[j] == c)
		j++;
	while (s[j] && s[j] != c)
	{
		dst[i] = s[j];
		i++;
		j++;
	}
	*k = j;
	dst[i] = '\0';
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dst;

	i = 0;
	j = 0;
	k = 0;
	dst = NULL;
	if (!s || !c)
		return (NULL);
	j = countwords(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * j + 1)))
		return (NULL);
	dst[j] = 0;
	while (i < j)
	{
		if (!(dst[i] = (char *)malloc(sizeof(char)
		* (countletters(&s[k], c) + 1))))
			return (NULL);
		fillarray(dst[i], s, &k, c);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
