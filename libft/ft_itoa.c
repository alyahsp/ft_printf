/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:59:45 by spalmaro          #+#    #+#             */
/*   Updated: 2016/11/03 19:04:13 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		checksign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int		absolutenbr(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int		ft_intlen(int n)
{
	int len;

	if (n < 0)
		n = n * -1;
	len = 1;
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	int		sign;
	int		rlen;
	char	*str;

	len = ft_intlen(n);
	sign = checksign(n);
	str = NULL;
	rlen = len + sign;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char *)malloc(sizeof(char) * (rlen + 1))))
		return (NULL);
	str[rlen] = '\0';
	if (!n)
		str[rlen] = 0;
	while (rlen >= 0)
	{
		if (sign == 1)
			str[0] = '-';
		str[--rlen] = absolutenbr(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
