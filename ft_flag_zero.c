/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 00:48:07 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/10 03:49:02 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

int		ft_numlen(long long nb)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int         ft_handle_width(char *p, int width)
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

int         ft_handle_width_precision(char *p, int width, int precision)
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
			while (--width > precision)
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

int        ft_flag_zero(const char *s, int *pos, va_list list)
{
	int width;
	int precision;
	char *p;
	int cpt;

	cpt = *pos;
	width = ft_atoi(s + *pos + 1);
	while (ft_isdigit(s[*pos]))
		*pos += 1;
	if (s[*pos] == '.')
		*pos += 1;
	precision = ft_atoi(s + *pos);
	while (ft_isdigit(s[*pos]))
		*pos += 1;
    p = ft_checkparam(*(s + *pos), list);
	if (precision == 0)
		cpt = ft_handle_width(p, width);
	else
		cpt = ft_handle_width_precision(p, width, precision);
	free(p);
	return (cpt + ft_strlen(s));
}