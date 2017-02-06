/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:24:48 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/02 13:25:28 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_charpadding(char str, t_form *form)
{
	int				space;
	int				tmp;

	space = form->padding - 1;
	tmp = space;
	if (form->mzflag == '-')
	{
		ft_putchar(str);
		ft_putnchar(' ', space);
	}
	else if (form->mzflag == '0')
	{
		ft_putnchar('0', space);
		ft_putchar(str);
	}
	else
	{
		ft_putnchar(' ', space);
		ft_putchar(str);
	}
	return (tmp);
}

int			ft_c(va_list args, t_form *form)
{
	int				i;
	unsigned char	c;

	i = 1;
	if (ft_strcmp(form->length_mod, "l") == 0)
		return (ft_lc(args, form));
	c = (unsigned char)va_arg(args, wchar_t);
	if (form->padding > 1)
		i += ft_charpadding(c, form);
	else
		write(1, &c, 1);
	return (i);
}
