/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:04:31 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/10 05:55:19 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

char		*ft_strrev(char *str);
int			ft_len(long long nb);
char		*ft_upper(char *str);
char		*ft_hex(long long nb);
int			ft_printf(const char *s, ...);
void		ft_printfparam(char c, va_list list);
int			ft_flag_zero(const char *s, int *pos, va_list list);
char		*ft_checkparam(char c, va_list list);
int			ft_flag_minus(const char *s, int *pos, va_list list);
int			ft_handle_width_precision(char *p, int width, int precision);
int			ft_handle_width(char *p, int width);
int			ft_width_precision(const char *s, int *pos, va_list list);
int			ft_norm_width(char *p, int width);
int			ft_norm_width_precision(char *p, int width, int precision);
#endif
