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


void	ft_precision(char *str, char *p, int flag)
{
	int len;
	int s_len;
	int i;
	int j;

	i = 0;
	j = 0;
	s_len = ft_strlen(str);
	len = ft_strlen(p);
	//printf("flaf : %d\n", flag);
	if (flag == 1)
	{
		if (len != 0 && s_len > len)
			ft_putstr_fd(str, 1);
		else if (len >= s_len)
		{
			i = len - s_len;
			p = ft_substr(str, s_len, len);
			ft_putstr_fd(p, 1);
		}
	}
	else if (flag == 0)
	{
		if (len != 0)
			ft_putstr_fd(str, 1);
		else
		{
			i = len - s_len;
			while (i < len)
			{
				p[i] = str[j];
				i++;
				j++;
			}
		ft_putstr_fd(p, 1);
		}
	}
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
				flag = 1;
			/*if (s[i] == 'c')
				ft_putchar_fd(va_arg(list, int), 1);
			if (s[i] == 's')
				ft_putstr_fd(va_arg(list, char *), 1);
				*/
				if (s[i] == 'd' || str[i] == 'i')
					ft_precision(ft_itoa(va_arg(list, int)), p, flag);
				if (s[i] == 'u')
					ft_precision(ft_itoa(va_arg(list, unsigned int)), p, flag);
				if (s[i] == 'x')
					ft_precision(ft_hex(va_arg(list, long long)), p, flag);
				if (s[i] == 'X')
					ft_precision(ft_upper(ft_hex(va_arg(list, long long))), p, flag);	
				if (s[i] == 'p')	
					ft_precision(ft_strjoin("0x", ft_hex(va_arg(list, long long))), p, flag);
			}
			if (s[i] == '.')
			{
				flag = 1;
				i++;
			}
			if (ft_isdigit(s[i]) == 1)
			{
				p = ft_width_precision(str, i, &i);
				flag = 1;
			}
			if (s[i] == 'c')
				ft_putchar_fd(va_arg(list, int), 1);
			if (s[i] == 's')
				ft_putstr_fd(va_arg(list, char *), 1);
			if (s[i] == 'd' || str[i] == 'i')
				ft_precision(ft_itoa(va_arg(list, int)), p, flag);
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
