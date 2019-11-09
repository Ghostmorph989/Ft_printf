/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:04:31 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/06 18:09:28 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFT_PRINTF_H
# define	LIBFT_PRINTF_H

#include	"libft.h"
#include	<stdarg.h>
#include    <stdio.h>

char		*ft_strrev(char *str);
int			ft_len(long long nb);
char		*ft_upper(char *str);
char		*ft_hex(long long nb);
int			ft_printf(const char *s, ...);
char        *ft_flagzero(char *str, int i, int *holder);
char        *ft_fill(int left_v, int right_v);
char        *ft_width_precision(char *str, int i, int *holder);
void	    ft_precision_flag(char *str, char *p);
void	    ft_precision(char *str, char *p);
#endif

