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

void	ft_check_specify(int fs0, int fs1)
{
	int i;

	i = fs0 - fs1;
	while (i)
	{
		ft_putchar_fd(' ', 1);
		i--;
	}
	//	ft_putstr_fd(va_arg(list, char *), 1);
	/*
	if (str[i] == 'd' || str[i] == 'i')
	{
		ft_putstr_fd(ft_itoa(va_arg(list, int)), 1);
	}
	if (str[i] == 'u')
		ft_putstr_fd(ft_itoa(va_arg(list, unsigned int)), 1);
	if (str[i] == 'x')
		ft_putstr_fd(ft_hex(va_arg(list, long long)), 1);
	if (str[i] == 'X')
		ft_putstr_fd(ft_upper(ft_hex(va_arg(list, long long))), 1);
		*/
}


void	ft_check_params(char *str, va_list list, int i)
{
	int fs0;
	int fs1;

	fs0 = 0;p
	fs1 = 0;
	if (str[i] == '*' || ft_isdigit(str[i]))
	{
		if (str[i] == '*')
			fs0 = va_arg(list, int);
		else
			fs0 = ft_atoi(&str[i]);
		i++;
		if (str[i] == '.')
			i++;
		if (str[i] == '*' || ft_isdigit(str[i]))
		{
			if (str[i] == '*')
				fs1 = va_arg(list, int);
			else
				fs1 = ft_atoi(&str[i]);
			i++;
		}
		ft_check_specify(fs0, fs1);
	}
}




int		ft_printf(const char *s, ...)
{
	char	*str;
	int		i;
	int		j;
	va_list list;
	va_start(list, s);

	i = 0;
	j = 0;
	str= ft_strdup(s);
	while (str[i] != '\0')
	{
		if ((str[i] != '%' || (str[i] == '%' && str[i + 1] == '%')) && str[i] != '\0')
			ft_putchar_fd(str[i], 1);
		else if (str[i] == '%')
		{
			i++;
			ft_check_params(str, list, i++);
			if (str[i] == 'c')
				ft_putchar_fd(va_arg(list, int), 1);
			if (str[i] == 's')
				ft_putstr_fd(va_arg(list, char *), 1);
			if (str[i] == 'd' || str[i] == 'i')
				ft_putstr_fd(ft_itoa(va_arg(list, int)), 1);
			if (str[i] == 'u')
				ft_putstr_fd(ft_itoa(va_arg(list, unsigned int)), 1);
			if (str[i] == 'x')
				ft_putstr_fd(ft_hex(va_arg(list, long long)), 1);
			if (str[i] == 'X')
				ft_putstr_fd(ft_upper(ft_hex(va_arg(list, long long))), 1);	
			if (str[i] == 'p')	
				ft_putstr_fd(ft_strjoin("0x", ft_hex(va_arg(list, long long))), 1);
		}
		i++;
	}
	va_end(list);
	free(str);
	return (i);
}
