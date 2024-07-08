/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:06 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/29 11:36:27 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_print_di_h(long nb, int *len)
{
	if (nb < 0)
	{
		ft_putchar('-');
		*len += 1;
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_print_di_h(nb / 10, len);
		ft_print_di_h(nb % 10, len);
	}
	else
	{
		ft_putchar(nb + '0');
		*len += 1;
	}
}

int	ft_print_di(int n)
{
	int	len;

	len = 0;
	ft_print_di_h(n, &len);
	return (len);
}
/*
int	main(void)
{
	int	number;
	int	length;

	number = -305441741;
	length = ft_print_di(number);
	ft_putchar('\n');
	printf("Length: %d\n", length);
	return (0);
}
*/