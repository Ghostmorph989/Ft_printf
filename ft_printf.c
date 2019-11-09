/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 05:04:05 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/06 22:14:04 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		ft_printf(const char *s, ...)
{
	char	*str;
	int		i;
	char 	*p;
	va_list list;
	va_start(list, s);
	int flag;

	i = 0;
	flag = 0;
	str = ft_strdup(s);
	while (str[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i] == '%' && s[i + 1] == '%')
				ft_putchar_fd(s[i], 1);
			i++;
			if (s[i] == '0')
			{
				p = ft_flagzero((char *)s, i, &i);
				/*if (s[i] == 'c')
					ft_putchar_fd(va_arg(list, int), 1);
				if (s[i] == 's')
					ft_putstr_fd(va_arg(list, char *), 1);
				*/
				if (s[i] == 'd' || str[i] == 'i')
					ft_precision_flag(ft_itoa(va_arg(list, int)), p);
				else if (s[i] == 'u')
					ft_precision_flag(ft_itoa(va_arg(list, unsigned int)), p);
				else if (s[i] == 'x')
					ft_precision_flag(ft_hex(va_arg(list, long long)), p);
				else if (s[i] == 'X')
					ft_precision_flag(ft_upper(ft_hex(va_arg(list, long long))), p);	
				else if (s[i] == 'p')	
					ft_precision_flag(ft_strjoin("0x", ft_hex(va_arg(list, long long))), p);
				i++;
			}
			if (s[i] == '.')
				i++;
			if (ft_isdigit(s[i]) == 1)
				p = ft_width_precision(str, i, &i);
			if (s[i] == 'c')
				ft_putchar_fd(va_arg(list, int), 1);
			else if (s[i] == 's')
				ft_putstr_fd(va_arg(list, char *), 1);
			else if (s[i] == 'd' || str[i] == 'i')
				ft_precision(ft_itoa(va_arg(list, int)), p);
			else if (s[i] == 'u')
				ft_putstr_fd(ft_itoa(va_arg(list, unsigned int)), 1);
			else if (s[i] == 'x')
				ft_putstr_fd(ft_hex(va_arg(list, long long)), 1);
			else if (s[i] == 'X')
				ft_putstr_fd(ft_upper(ft_hex(va_arg(list, long long))), 1);	
			else if (s[i] == 'p')	
				ft_putstr_fd(ft_strjoin("0x", ft_hex(va_arg(list, long long))), 1);
		}
		if (!ft_strnstr(s + i, "cspdiuxX%", 1))
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(list);
	free(str);
	return (i);
}
