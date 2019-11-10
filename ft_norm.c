/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 05:31:54 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/10 07:26:14 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_norm_width_precision(char *p, int width, int precision)
{
	int		cpt;
	int		len;

	len = ft_strlen(p);
	cpt = len;
	if (width >= precision)
	{
		if (width < len)
			ft_putstr_fd(p, 1);
		else
		{
			while (width-- > len)
			{
				ft_putchar_fd(' ', 1);
				cpt++;
			}
		}
		ft_putstr_fd(p, 1);
	}
	else if (width < precision)
	{
		if (p[0] == '-')
		{
			ft_putchar_fd('-', 1);
			cpt++;
			p[0] = '0';
		}
		while (precision-- > len)
		{
			ft_putchar_fd('0', 1);
			cpt++;
		}
		ft_putstr_fd(p, 1);
	}
	return (cpt);
}

int			ft_norm_width(char *p, int width)
{
	int		len;
	int		cpt;

	len = ft_strlen(p);
	cpt = len;
	if (width != 0)
	{
		if (width < len)
			ft_putstr_fd(p, 1);
		else
		{
			while (width-- > len)
			{
				ft_putchar_fd(' ', 1);
				cpt++;
			}
			if (p[0] == '-')
			{
				ft_putchar_fd('-', 1);
				p = p + 1;
				width--;
				cpt++;
			}
			ft_putstr_fd(p, 1);
		}
	}
	return (cpt);
}
int		ft_width_precision(const char *s, int *pos, va_list list)
{
	int		width;
	int		precision;
	char	*p;
	int		cpt;

	p = ft_strdup("");
	cpt = *pos;
	width = ft_atoi(s + *pos);
	while (ft_isdigit(s[*pos]))
		*pos += 1;
	if (s[*pos] == '.')
		*pos += 1;
	precision = ft_atoi(s + *pos);
	while (ft_isdigit(s[*pos]))
		*pos += 1;
	if (precision != 0)
	{
		p = ft_checkparam(*(s + *pos), list);
		cpt = ft_norm_width_precision(p, width, precision);
		free(p);
	}
	else
	{
		p = ft_checkparam(*(s + *pos), list);
		cpt = ft_norm_width(p, width);
		free(p);
	}
	return (cpt);
}
