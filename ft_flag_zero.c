/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 00:48:07 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/10 00:48:09 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

int         ft_advanced_isdigit(char *str, int i)
{
    while (ft_isdigit(str[i]) && str[i] != '\0')
            i++;
        return (i);
}

int         ft_getnum(char *str, int i)
{
    return (ft_atoi(str + i));
}

char       *ft_fill_flag(int left_v, int right_v)
{
    char *s;
    int i;

    i = 0;
    s = NULL;
    if (right_v >= left_v)
    {
        s = (char *)malloc(sizeof(char) * (right_v + 1));
        s[right_v] = '\0';
        s = ft_memset(s, '0', right_v);
    }
    else if (left_v > right_v)
    {
        s = (char *)malloc(sizeof(char) * (left_v + 1));
        s[left_v] = '\0';
        s = ft_memset(s, ' ', left_v - right_v);
        s = ft_memset(s , '0', left_v);
    }
    return (s);
}

char        *ft_width_precision_flag(char *str, int i, int *holder)
{
    int     left_v;
    int     right_v;
    char    *s;
    char    *p;

    left_v = 0;
    right_v = 0;
    s = ft_strdup("");;
    p = ft_strdup("");;
    left_v = ft_getnum(str, i);
    //printf("%d\n", left_v);
    i = ft_advanced_isdigit(str, i);
    if (str[i] == '.')
        i++;
    right_v = ft_getnum(str, i);
    //printf("%d\n", right_v);
    i = ft_advanced_isdigit(str, i);
    p = ft_fill(left_v, right_v);
    *holder = i;
    //printf("line = <%s>\n", str + i);
    return (p);
}

char        *ft_flagzero(char *str, int i, int *holder)
{
    char *p;

    p = ft_strdup("");
    //printf("%d\n", i);
    if (str[i] == '0')
    {
        p = ft_width_precision_flag(str, i, holder);
    }
    i = *holder;
    //printf("%d\n", i);
    return (p);
}