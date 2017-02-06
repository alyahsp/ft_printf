/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:35:06 by spalmaro          #+#    #+#             */
/*   Updated: 2016/11/03 17:23:23 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t llen;

	i = 0;
	j = 0;
	if (!ft_strlen(needle))
		return ((char*)haystack);
	if (len)
		len = len + 1;
	while (len + 1 > 0 && haystack[i])
	{
		len--;
		llen = len;
		while (haystack[i + j] == needle[j] && llen-- > 0)
		{
			if (j == (ft_strlen(needle) - 1))
				return ((char *)(haystack + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
