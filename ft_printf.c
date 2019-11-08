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
	int		j;
	va_list list;
	va_start(list, s);

	i = 0;
	j = 0;
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
				ft_flagzero((char *)s, i, &j);
				i = j + 1;
			}
			if (s[i] == 'c')
				ft_putchar_fd(va_arg(list, int), 1);
			if (s[i] == 's')
				ft_putstr_fd(va_arg(list, char *), 1);
			if (s[i] == 'd' || str[i] == 'i')
				ft_putstr_fd(ft_itoa(va_arg(list, int)), 1);
			if (s[i] == 'u')
				ft_putstr_fd(ft_itoa(va_arg(list, unsigned int)), 1);
			if (s[i] == 'x')
				ft_putstr_fd(ft_hex(va_arg(list, long long)), 1);
			if (s[i] == 'X')
				ft_putstr_fd(ft_upper(ft_hex(va_arg(list, long long))), 1);	
			if (s[i] == 'p')	
				ft_putstr_fd(ft_strjoin("0x", ft_hex(va_arg(list, long long))), 1);
	
		}
		else if (s[i] != '%')
			ft_putchar_fd(s[i], 1);

		i++;
	}
	va_end(list);
	free(str);
	return (i);
}
