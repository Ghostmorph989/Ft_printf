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


void	ft_checkparam_flag(char c, va_list list, char *p)
{
	if (c == 'd' || c == 'i')
		ft_precision_flag(ft_itoa(va_arg(list, int)), p);
	else if (c == 'u')
		ft_precision_flag(ft_itoa(va_arg(list, unsigned int)), p);
	else if (c == 'x')
		ft_precision_flag(ft_hex(va_arg(list, long long)), p);
	else if (c == 'X')
		ft_precision_flag(ft_upper(ft_hex(va_arg(list, long long))), p);	
	else if (c == 'p')	
		ft_precision_flag(ft_strjoin("0x", ft_hex(va_arg(list, long long))), p);
}

void	ft_checkparam(char c, va_list list, char *p)
{
	if (c == 's')
		ft_precision(va_arg(list, char *), p);
	else if (c == 'd' || c == 'i')
		ft_precision(ft_itoa(va_arg(list, int)), p);
	else if (c == 'u')
		ft_precision(ft_itoa(va_arg(list, unsigned int)), p);
	else if (c == 'x')
		ft_precision(ft_hex(va_arg(list, long long)), p);
	else if (c == 'X')
		ft_precision(ft_upper(ft_hex(va_arg(list, long long))), p);	
	else if (c == 'p')	
		ft_precision(ft_strjoin("0x", ft_hex(va_arg(list, long long))), p);
}

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
				ft_checkparam_flag(s[i], list, p);				
				i++;
			}
			else if (s[i] == '-')
				p = ft_flagminus();
			if (s[i] == '.')
				i++;
			if (ft_isdigit(s[i]) == 1)
				p = ft_width_precision(str, i, &i);
			ft_checkparam(s[i], list, p);
			i++;
		}
		if (!ft_strnstr(s + i, "cspdiuxX%", 1))
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(list);
	free(str);
	return (i);
}
