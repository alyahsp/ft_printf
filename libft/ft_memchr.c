/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:34:36 by spalmaro          #+#    #+#             */
/*   Updated: 2016/11/03 17:16:16 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *dst;

	dst = (unsigned char *)s;
	while (dst && n > 0)
	{
		if (*dst == (unsigned char)c)
			return (dst);
		dst++;
		n--;
	}
	return (NULL);
}
