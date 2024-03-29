/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 05:04:05 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/10 06:09:41 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf(const char *s, ...)
{
	int		i;
	va_list	list;
	int		cpt;

	va_start(list, s);
	i = 0;
	cpt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (!ft_strnstr(s + i, "cspdiuxX%", 1))
				ft_printfparam(s[++i], list);
			if ((s[i] == '%' && s[i + 1] == '%'))
				ft_putchar_fd(s[i++], 1);
			if (s[i] == '-' && s[i + 1] != '-')
				cpt = ft_flag_minus(s, &i, list);
			else if (s[i] == '0')
				cpt = ft_flag_zero(s, &i, list);
			else if (ft_isdigit(s[i]) || s[i] == '.' || s[i] == 42)
				cpt = ft_width_precision(s, &i, list);
			i++;
		}else
			ft_putchar_fd(s[i++], 1);
	}
	va_end(list);
	return (cpt);
}
