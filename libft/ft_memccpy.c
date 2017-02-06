/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:34:34 by spalmaro          #+#    #+#             */
/*   Updated: 2016/11/05 16:27:49 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*sc;
	unsigned char	*dt;

	sc = (unsigned char *)src;
	dt = (unsigned char *)dst;
	while (n > 0)
	{
		if (*sc == (unsigned char)c)
		{
			*dt++ = *sc;
			return ((void *)dt);
		}
		else
			*dt++ = *sc++;
		n--;
	}
	return (NULL);
}
