/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:06:55 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/29 13:22:56 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_hexup(unsigned int n)
{
	int	length;

	length = 0;
	if (n >= 16)
	{
		length += ft_print_hexup(n / 16);
		length += ft_print_hexup(n % 16);
	}
	else
	{
		if (n <= 9)
			length += ft_putchar(n + '0');
		else
			length += ft_putchar(n - 10 + 'A');
	}
	return (length);
}
