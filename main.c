/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:09:53 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/10 06:09:43 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	void *a = "gdfgs";
	//printf("/***********************************************\\\n");
	//printf("Keep your head strong : %015.16d", 42545245);
	//printf("/***********************************************\\\n");
	ft_printf("%p\n", a);
	printf("%p\n",a );
	return (0);
}
