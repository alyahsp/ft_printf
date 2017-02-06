/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:39:29 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/02 21:45:30 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void		ft_flags(t_form *form, char *format, int *i)
{
	while (format[*i] && (isflag(format[*i]) == 1))
	{
		if (format[*i] == '+')
			form->spflag = '+';
		else if (format[*i] == ' ' && (form->spflag != '+'))
			form->spflag = ' ';
		else if (format[*i] == '-')
			form->mzflag = '-';
		else if (format[*i] == '0' && (form->mzflag != '-'))
			form->mzflag = '0';
		else if (format[*i] == '#')
			form->pflag = '#';
		(*i)++;
	}
}

void		ft_prec_pad(t_form *form, char *format, int *i)
{
	if (format[*i] >= '0' && format[*i] <= '9')
		form->padding = ft_atoi(&format[*i]);
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	if (format[*i] == '.' && format[*i + 1] >= '0' && format[*i + 1] <= '9')
	{
		(*i)++;
		form->precision = ft_atoi(&format[*i]);
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
	}
	else if (format[*i] == '.')
	{
		(*i)++;
		form->precision = 0;
	}
}

void		ft_length_mod(t_form *form, char *frmt, int *i)
{
	while (frmt[*i] && (islmodifier(&frmt[*i]) > 0))
	{
		if ((islmodifier(&frmt[*i]) == 1) &&
		(islmodifier(form->length_mod) <= 1))
		{
			form->length_mod = "hh";
			(*i)++;
		}
		else if ((islmodifier(&frmt[*i]) == 2) &&
		(islmodifier(form->length_mod) <= 2))
			form->length_mod = "h";
		else if (frmt[*i] == 'j' && islmodifier(form->length_mod) <= 3)
			form->length_mod = "j";
		else if (frmt[*i] == 'l' && frmt[*i + 1] == 'l')
		{
			form->length_mod = "ll";
			(*i)++;
		}
		else if (frmt[*i] == 'l' && islmodifier(form->length_mod) <= 3)
			form->length_mod = "l";
		else if (frmt[*i] == 'z' && islmodifier(form->length_mod) <= 3)
			form->length_mod = "z";
		(*i)++;
	}
}

int			ft_conversion(t_form *form, va_list args, char *c, int i)
{
	int		(*convert[5])(va_list, t_form*);
	char	*conversion;

	conversion = "sSpcCdDioOuUxX";
	convert[0] = &ft_s;
	convert[1] = &ft_ls;
	convert[2] = &ft_p;
	convert[3] = &ft_c;
	convert[4] = &ft_lc;
	while (conversion[i])
	{
		if (conversion[i] == c[0] && (i >= 5))
			return (ft_convertint(va_arg(args, long long), form, c[0]));
		else if (conversion[i] == c[0])
			return (convert[i])(args, form);
		i++;
	}
	if (c[0] == '%')
		return (writeperct(c, form));
	else
		return (writechar(c[0], form));
}
