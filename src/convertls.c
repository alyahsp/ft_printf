/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:39:14 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/29 15:46:53 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_octlen(wchar_t *s, t_form *form)
{
	int		len;
	int		sp;

	len = 0;
	if (form->precision == -1)
		form->precision = ft_wcslen(s) * 4;
	while (*s)
	{
		sp = bitlen(*s);
		if (sp > 16 && (len + 4 <= form->precision))
			len += 4;
		else if (sp > 11 && (len + 3 <= form->precision))
			len += 3;
		else if (sp > 7 && (len + 2 <= form->precision))
			len += 2;
		else if (sp <= 7 && (len + 1 <= form->precision))
			len++;
		else
			break ;
		s++;
	}
	return (len);
}

static int	ft_wchartpadding(t_form *form, int oct)
{
	int		space;
	int		tmp;

	space = form->padding - oct;
	tmp = space;
	if (form->mzflag == '-')
		ft_putnchar(' ', tmp);
	return (space);
}

void		ft_subls(wchar_t *str, t_form *form, int *total, int oct)
{
	char	char_oct[5];
	int		len;
	int		k;

	k = 0;
	len = 0;
	ft_bzero(char_oct, 5);
	while (*str && len < form->precision)
	{
		ft_filloctet(*str, char_oct, &oct, bitlen(*str));
		if ((len += oct) > form->precision)
			break ;
		if (form->padding > oct && k == 0 && form->mzflag != '-' &&
		form->padding > form->precision)
		{
			(*total) += ft_wcharpadding(form, *total, char_oct);
			k = 1;
		}
		else
			ft_putstr(char_oct);
		oct = 0;
		str++;
	}
	if (form->padding > oct && form->mzflag == '-')
		(*total) += ft_wchartpadding(form, *total);
}

int			ft_ls(va_list args, t_form *form)
{
	int		total;
	char	char_oct[5];
	wchar_t	*str;

	if (!(str = va_arg(args, wchar_t *)))
		str = L"(null)";
	total = 0;
	ft_bzero(char_oct, 5);
	if (form->precision == 0)
		total += ft_wcharpadding(form, 0, char_oct);
	else
		total += ft_octlen(str, form);
	ft_subls(str, form, &total, 0);
	return (total);
}
