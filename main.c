/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:09:53 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/06 22:14:55 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int a = -9999999;

	//printf("/***********************************************\\\n");
	//printf("Keep your head strong : %015.16d", 42545245);
	//printf("/***********************************************\\\n");
	ft_printf("Keep your head strong :%20d\n", a);
	printf("Keep your head strong :%20d\n", a);
	return (0);
}
