/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:47:52 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/16 17:07:11 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_base_size(int nbr, int base)
{
	int len;
	int sign;

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
