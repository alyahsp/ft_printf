/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:47:14 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/02 21:38:45 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(long long nbr, int base)
{
	int		len;
	int		sign;

	sign = 0;
	len = 1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		if (base == 10)
			sign = 1;
	}
	while (nbr >= base)
	{
		len++;
		nbr = nbr / base;
	}
	return (len + sign);
}

static char		*ft_convert_base(int sign, int len, long long value, int base)
{
	char	*str;
	char	*alphabet;

	alphabet = "0123456789abcdef";
	if (!(str = (char *)malloc(sizeof(char) * (len + sign + 1))))
		return (NULL);
	str[len] = '\0';
	if (sign == 1)
		str[0] = '-';
	while (--len >= (0 + sign))
	{
		str[len] = alphabet[(value % base)];
		value /= base;
	}
	return (str);
}

char			*ft_lltoa_base(long long value, int base)
{
	int		sign;
	int		len;

	sign = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (value < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	len = ft_intlen(value, base);
	if (value < 0)
	{
		value *= -1;
		if (base == 10)
			sign = 1;
	}
	return (ft_convert_base(sign, len, value, base));
}
