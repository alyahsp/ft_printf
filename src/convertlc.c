/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertlc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 15:19:24 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/29 15:23:20 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_wcharpadding(t_form *form, int oct, char *char_oct)
{
	int		space;
	int		tmp;

	space = form->padding - oct;
	tmp = space;
	if (form->mzflag == '-')
	{
		ft_putstr(char_oct);
		while (tmp-- > 0)
			ft_putchar(' ');
	}
	else if (form->mzflag == '0')
	{
		while (tmp-- > 0)
			ft_putchar('0');
		ft_putstr(char_oct);
	}
	else
	{
		while (tmp-- > 0)
			ft_putchar(' ');
		ft_putstr(char_oct);
	}
	return (space);
}

void		ft_filloctet(wchar_t c, char *char_oct, int *i, int len)
{
	if (len > 7)
	{
		if (len > 11)
		{
			if (len > 16)
			{
				char_oct[(*i)++] = ((c >> 18) & 0b00000111) | 0b11110000;
				char_oct[(*i)++] = ((c >> 12) & 0b00111111) | 0b10000000;
			}
			else
				char_oct[(*i)++] = ((c >> 12) & 0b00001111) | 0b11100000;
			char_oct[(*i)++] = ((c >> 6) & 0b00111111) | 0b10000000;
		}
		else
			char_oct[(*i)++] = ((c >> 6) & 0b00011111) | 0b11000000;
		char_oct[(*i)++] = (c & 0b00111111) | 0b10000000;
	}
	else
		char_oct[(*i)++] = (char)c;
	char_oct[(*i)] = '\0';
}

int			ft_lc(va_list args, t_form *form)
{
	int		len;
	int		oct;
	wchar_t	str;
	char	char_oct[5];

	oct = 0;
	str = va_arg(args, wchar_t);
	len = bitlen(str);
	ft_filloctet(str, char_oct, &oct, len);
	if (form->padding > oct)
		oct += ft_wcharpadding(form, oct, char_oct);
	else
		ft_putstr(char_oct);
	str == 0 ? write(1, "\0", 1) : 0;
	return (oct);
}
