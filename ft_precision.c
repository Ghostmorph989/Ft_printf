/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:54:55 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/09 21:54:56 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_precision_flag(char *str, char *p)
{
	int len;
	int s_len;
	int i;
	int j;

	i = 0;
	j = 0;
	s_len = ft_strlen(str);
    //printf("%s\n", str);
	if (p == NULL)
		ft_strdup("");
	len = ft_strlen(p);
    //printf("s_len ; %d, || len = %d", s_len, len);
	if (s_len > len && len >= 0)
		ft_putstr_fd(str, 1);
	if (len > s_len)
	{
		if (str[i] == '-')
		{
			ft_putchar_fd('-', 1);
			i++;
			j++;
		}
		i = len - s_len;
		while (i < len)
		{
			p[i] = str[j];
			i++;
			j++;
		}
		p[i] = '\0';
		ft_putstr_fd(p, 1);
	}
}
void	ft_precision(char *str, char *p)
{
	int len;
	int s_len;
	int i;
	int j;

	i = 0;
	j = 0;
	s_len = ft_strlen(str);
    printf("%s\n", p);
	if (p == NULL)
		ft_strdup("");
	len = ft_strlen(p);
    printf("s_len ; %d, || len = %d", s_len, len);
	if (s_len >= len)
		ft_putstr_fd(str, 1);
	else if (len > s_len)
	{
		i = len - s_len;
		while (i < len)
		{
			p[i] = str[j];
			i++;
			j++;
		}
		p[i] = '\0';
		ft_putstr_fd(p, 1);
	}
}