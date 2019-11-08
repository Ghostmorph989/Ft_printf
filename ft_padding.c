/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:27:30 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/07 13:27:37 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

void        ft_fill(int left_v, int right_v)
{
    char *s;
    int i;

    i = 0;
    s = NULL;
    if (right_v > left_v)
    {
        s = (char *)malloc(sizeof(char) * (right_v + 1));
        s = ft_memset(s, '0', right_v);
    }
    else
    {
        s = (char *)malloc(sizeof(char) * (left_v + 1));
        s = ft_memset(s, '0', left_v);
         s = ft_memset(s, ' ', left_v - right_v);
    }

   /* while (s[i] != '\0' && )
    {

    }*/
    printf("%s\n", s);
}

void        ft_flagzero(char *str, int i, int *holder)
{
    int     left_v;
    int     right_v;
    char    *s;

    left_v = 0;
    right_v = 0;
    s = NULL;
    if (str[i] == '0')
    {
        left_v = ft_atoi(str + i);
        while (ft_isdigit(str[i]) && str[i] != '\0')
            i++;
        if (str[i] == '.')
            i++;
        right_v = ft_atoi(str + i);
        printf("\n%d || %d\n", left_v, right_v);
        ft_fill(left_v, right_v);
    }
    *holder = i + 1;
}
