/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:47:14 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/02 13:35:05 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(unsigned long long nbr, int base)
{
	int		len;

	len = 1;
	while (nbr >= (unsigned long long)base)
	{
		len++;
		nbr = nbr / base;
	}
	return (len);
}

static char		*ft_convert_base(int len, unsigned long long value,
	int base, char *str)
{
	char	*alphabet;

	alphabet = "0123456789abcdef";
	while (--len >= 0)
	{
		str[len] = alphabet[(value % base)];
		value /= base;
	}
	return (str);
}

char			*ft_ulltoa_base(unsigned long long value, int base)
{
	int		len;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_intlen(value, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	return (ft_convert_base(len, value, base, str));
}
