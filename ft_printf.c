/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 05:04:05 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/10 01:00:29 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int         ft_norm_width_precision(char *p, int width, int precision)
{
	int cpt;
	int len;

	len = ft_strlen(p) - 1;
	cpt = len;
	if (width > precision)
	{
		if (width < len)
			ft_putstr_fd(p, 1);
		else
		{
			while (width-- > precision)
			{
				ft_putchar_fd(' ', 1);
				cpt++;
			}
		}
	}
	if (p[0] == '-')
	{
		ft_putchar_fd('-', 1);
		p[0] = '0';
		cpt++;
	}
	while (--precision > len)
	{
		ft_putchar_fd('0', 1);
		cpt++;
	}
	ft_putstr_fd(p, 1);
	return (cpt);
}
int         ft_norm_width(char *p, int width)
{
	int len;
	int cpt;

	len = ft_strlen(p) - 1;
	cpt = len;
	if (width != 0)
	{
	if (width < len)
		ft_putstr_fd(p, 1);
	else
	{
		if (p[0] == '-')
		{
			ft_putchar_fd('-', 1);
			p[0] = '0';
			width--;
			cpt++;
		}
		while (width-- && width > len)
		{
			ft_putchar_fd('0', 1);
			cpt++;
		}
		ft_putstr_fd(p, 1);
	}
	}
	return (cpt);
}
int		ft_width_precision(const char *s, int *pos, va_list list)
{
	int width;
	int precision;
	char *p;
	int cpt;

	p = NULL;
	cpt = *pos;
	width = ft_atoi(s + *pos);
	while (ft_isdigit(s[*pos]))
		*pos += 1;
	if (s[*pos] == '.')
		*pos += 1;
	precision = ft_atoi(s + *pos);
	while (ft_isdigit(s[*pos]))
		*pos += 1;
	//printf("width : %d || precison : %d\n", width, precision);
	if (precision != 0)
	{
    	p = ft_checkparam(*(s + *pos), list);
		cpt = ft_norm_width_precision(p, width, precision);
		free(p);
	}
	else
		cpt = ft_norm_width(p, width);
	return (cpt + ft_strlen(s));
}


int		ft_printf(const char *s, ...)
{
	int		i;
	va_list list;
	va_start(list, s);
	int cpt;

	i = 0;
	cpt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i] == '%' && s[i + 1] == '%')
				ft_putchar_fd(s[i], 1);
			i++;
			if (s[i] == '0')
			{
				cpt = ft_flag_zero(s, &i, list);
				i++;
			}
			else if (s[i] == '-')
			{
				cpt = ft_flag_minus(s, &i, list);
				i++;
			}
			else if (ft_isdigit(s[i]))
			{
				cpt = ft_width_precision(s, &i, list);
				i++;
			}
			else
			{
				ft_printfparam(s[i], list);
				i++;
			}
		}
		if (!ft_strnstr(s + i, "cspdiuxX%", 1))
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(list);
	return (cpt);
}
