/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:39:05 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/02 13:37:36 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_form	*struct_init(void)
{
	t_form	*form;

	if (!(form = malloc(sizeof(t_form))))
		return (NULL);
	form->mzflag = '\0';
	form->spflag = '\0';
	form->pflag = '\0';
	form->length_mod = "\0";
	form->precision = -1;
	form->padding = 0;
	return (form);
}

int		arg_parse(va_list args, char *format, int *i)
{
	int		len;
	t_form	*form;

	len = 0;
	form = struct_init();
	(*i)++;
	while (format[*i])
	{
		ft_flags(form, format, i);
		ft_prec_pad(form, format, i);
		ft_length_mod(form, format, i);
		if ((len = ft_conversion(form, args, &format[*i], 0)) >= 0)
		{
			(*i)++;
			break ;
		}
	}
	free(form);
	return (len);
}

int		ft_parse(const char *format, va_list args)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	str = (char *)format;
	while (str[i])
	{
		if (str[i] == '%')
			len += arg_parse(args, str, &i);
		else if (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
			len++;
		}
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;

	len = 0;
	if (format)
	{
		va_start(args, format);
		len = (ft_parse(format, args));
		va_end(args);
	}
	return (len);
}
