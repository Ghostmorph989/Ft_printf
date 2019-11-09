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
	int p_len;
	int s_len;
	int i;
	int j;

	i = 0;
	j = 0;
	s_len = ft_strlen(str);
    //printf("%s\n", str);
	if (p == NULL)
		ft_strdup("");
	p_len = ft_strlen(p);
    //printf("s_len ; %d, || len = %d", s_len, p_len);
	if (s_len >= p_len && p_len >= 0)
		ft_putstr_fd(str, 1);
	if (p_len > s_len)
	{
        while (p[j] != '\0' && (p[j] == ' ' || p[j] == '0'))
        {
            if (str[i] == '-' && p[j + 1] == '0')
            {
                p[j] = '-';
                str[i] = '0';
            }
            j++;
        }
		while (i < s_len)
		{
			p[i + p_len - s_len] = str[i];
			i++;
		}
		p[p_len] = '\0';
		ft_putstr_fd(p, 1);
	}
}
void	ft_precision(char *str, char *p)
{
	int p_len;
	int s_len;
	int i;
	int j;

	i = 0;
	j = 0;
	s_len = ft_strlen(str);
    //printf("%s\n", str);
	if (p == NULL)
		ft_strdup("");
	p_len = ft_strlen(p);
    //printf("s_len ; %d, || len = %d", s_len, p_len);
	if (s_len >= p_len && p_len >= 0)
		ft_putstr_fd(str, 1);
	if (p_len > s_len)
	{
        while (p[j] != '\0' && (p[j] == ' ' || p[j] == '0'))
        {
            if (str[i] == '-' && p[j + 1] == '0')
            {
                p[j] = '-';
                str[i] = '0';
            }
            j++;
        }
		while (i < s_len)
		{
			p[i + p_len - s_len] = str[i];
			i++;
		}
		p[p_len] = '\0';
		ft_putstr_fd(p, 1);
	}
}