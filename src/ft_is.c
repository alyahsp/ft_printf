/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 18:49:08 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/22 18:49:09 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		isflag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}

int		islmodifier(char *c)
{
	if (!c)
		return (0);
	else if (ft_strncmp(c, "hh", 2) == 0)
		return (1);
	else if (ft_strncmp(c, "ll", 2) == 0)
		return (4);
	else if (c[0] == 'h')
		return (2);
	else if (c[0] == 'j' || c[0] == 'l' || c[0] == 'z')
		return (3);
	return (0);
}
