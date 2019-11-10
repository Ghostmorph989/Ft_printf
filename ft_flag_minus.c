/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 04:35:22 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/10 05:51:11 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_flag_minus(const char *s, int *pos, va_list list)
{
	int		width;
	int		precision;
	int		len;
	char	*p;
	int		cpt;

	width = 0;
	cpt = 0;
	precision = 0;
	*pos += 1;
	if (s[*pos] == '0')
		return (ft_flag_zero(s, pos, list));
	width = ft_atoi(s + *pos);
	while (ft_isdigit(s[*pos]))
		*pos += 1;
	if (s[*pos] == '.')
		*pos += 1;
	precision = ft_atoi(s + *pos);
	while (ft_isdigit(s[*pos]))
		*pos += 1;
	p = ft_checkparam(*(s + *pos), list);
	len = ft_strlen(p) - 1;
	if (precision == 0)
		ft_putstr_fd(p, 1);
	else if (width < precision)
	{
		if (p[0] == '-')
		{
			ft_putchar_fd('-', 1);
			p[0] = '0';
			cpt++;
			width--;
			//p = p + 1;
		}
		while (--precision > len)
		{
			ft_putchar_fd('0', 1);
			cpt++;
			width--;
		}
		ft_putstr_fd(p, 1);
	}
	else
	{
		if (p[0] == '-')
		{
			ft_putchar_fd('-', 1);
			cpt++;
			p = p + 1;
		}
		while (--precision > len)
		{
			ft_putchar_fd('0', 1);
			cpt++;
			width--;
		}
		ft_putstr_fd(p, 1);
	}
	while (--width > len)
		ft_putchar_fd(' ', 1);
	return (cpt);
}
