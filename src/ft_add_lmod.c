/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_lmod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:57:55 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/28 19:55:04 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*add_lmodoux(t_form *form, long long nbr, char c, char *str)
{
	int		base;

	if (c == 'o' || c == 'O')
		base = 8;
	else if (c == 'x' || c == 'X')
		base = 16;
	else
		base = 10;
	if (ft_strcmp(form->length_mod, "ll") == 0)
		str = ft_ulltoa_base((unsigned long long)nbr, base);
	else if (ft_strcmp(form->length_mod, "l") == 0)
		str = ft_ulltoa_base((unsigned long)nbr, base);
	else if (ft_strcmp(form->length_mod, "hh") == 0)
		str = ft_ulltoa_base((unsigned char)nbr, base);
	else if (ft_strcmp(form->length_mod, "h") == 0)
		str = ft_ulltoa_base((unsigned short)nbr, base);
	else if (ft_strcmp(form->length_mod, "j") == 0)
		str = ft_ulltoa_base((uintmax_t)nbr, base);
	else if (ft_strcmp(form->length_mod, "z") == 0)
		str = ft_ulltoa_base((signed long)nbr, base);
	else
		str = ft_ulltoa_base((unsigned int)nbr, base);
	c == 'X' ? (str = ft_strtoupper(str)) : 0;
	return (str);
}

char		*ft_add_lmod(t_form *form, long long nbr, char c)
{
	char *str;

	str = NULL;
	if (c != 'd' && c != 'i' && c != 'D')
		return (add_lmodoux(form, nbr, c, str));
	else if (ft_strcmp(form->length_mod, "ll") == 0)
		str = ft_lltoa_base((long long)nbr, 10);
	else if (ft_strcmp(form->length_mod, "l") == 0)
		str = ft_lltoa_base((long)nbr, 10);
	else if (ft_strcmp(form->length_mod, "hh") == 0)
		str = ft_lltoa_base((signed char)nbr, 10);
	else if (ft_strcmp(form->length_mod, "h") == 0)
		str = ft_lltoa_base((short)nbr, 10);
	else if (ft_strcmp(form->length_mod, "j") == 0)
		str = ft_lltoa_base((intmax_t)nbr, 10);
	else if (ft_strcmp(form->length_mod, "z") == 0)
		str = ft_lltoa_base((signed long)nbr, 10);
	else
		str = ft_itoa_base((int)nbr, 10);
	return (str);
}
