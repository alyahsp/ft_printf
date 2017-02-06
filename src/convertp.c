/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:13:48 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/02 20:46:37 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		writeperct(char *c, t_form *form)
{
	int		len;
	int		i;
	char	*tmp;

	len = 1;
	i = 0;
	tmp = ft_strdup("%");
	while (c[i] && c[i] != '%')
	{
		tmp = ft_strcat(tmp, &c[i]);
		i++;
		len++;
	}
	if (form->padding > (int)ft_strlen(tmp))
	{
		form->precision = (int)ft_strlen(tmp);
		tmp = ft_strpadding(tmp, form, 0);
	}
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}

int		writechar(char c, t_form *form)
{
	int		x;

	x = (form->padding > 0) ? (form->padding - 1) : 0;
	if (form->padding > 0 && form->mzflag == '0')
		ft_putnchar('0', form->padding - 1);
	else if (form->padding > 0 && form->mzflag != '-')
		ft_putnchar(' ', form->padding - 1);
	ft_putchar(c);
	if (form->padding > 0 && form->mzflag == '-')
		ft_putnchar(' ', form->padding - 1);
	return (1 + x);
}
