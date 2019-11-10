/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:29:56 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/10 05:45:41 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printfparam(char c, va_list list)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(list, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(list, char *), 1);
	else if (c == 'd' || c == 'i')
		ft_putstr_fd(ft_itoa(va_arg(list, int)), 1);
	else if (c == 'u')
		ft_putstr_fd(ft_itoa(va_arg(list, unsigned int)), 1);
	else if (c == 'x')
		ft_putstr_fd(ft_hex(va_arg(list, long long)), 1);
	else if (c == 'X')
		ft_putstr_fd(ft_upper(ft_hex(va_arg(list, long long))), 1);
	else if (c == 'p')
		ft_putstr_fd(ft_strjoin("0x", ft_hex(va_arg(list, long long))), 1);
}

char	*ft_checkparam(char c, va_list list)
{
	char p[2];
	if (c == 'c')
	{
		p[0] = va_arg(list, int);
		p[1] = '\0';
		return(ft_strdup(p));
	}
	else if (c == 's')
		return (va_arg(list, char *));
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(list, int)));
	else if (c == 'u')
		return (ft_itoa(va_arg(list, unsigned int)));
	else if (c == 'x')
		return (ft_hex(va_arg(list, long long)));
	else if (c == 'X')
		return (ft_upper(ft_hex(va_arg(list, long long))));
	else if (c == 'p')
		return (ft_strjoin("0x", ft_hex(va_arg(list, long long))));
	return (ft_strdup(""));
}
