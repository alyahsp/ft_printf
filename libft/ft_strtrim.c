/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:42:36 by spalmaro          #+#    #+#             */
/*   Updated: 2016/11/07 18:22:58 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countbegspace(const char *s)
{
	int space;
	int i;

	space = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		space++;
		i++;
	}
	if (s[i] == '\0')
		return (0);
	return (space);
}

static int		countendspace(const char *s)
{
	int len;
	int space;
	int i;

	len = ft_strlen(s);
	space = 0;
	i = 0;
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
	{
		len--;
		space++;
	}
	if (s[i] == '\0')
		return (0);
	return (space);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		space;
	int		len;
	char	*dst;

	i = 0;
	if (!s)
		return (NULL);
	space = countbegspace(s) + countendspace(s);
	len = ft_strlen(s) - space;
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dst[i] = s[countbegspace(s) + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
