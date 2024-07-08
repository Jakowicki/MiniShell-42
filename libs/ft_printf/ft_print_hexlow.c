/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexlow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:55:07 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/29 13:23:02 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_hexlow(unsigned int n)
{
	int	length;

	length = 0;
	if (n >= 16)
	{
		length += ft_print_hexlow(n / 16);
		length += ft_print_hexlow(n % 16);
	}
	else
	{
		if (n <= 9)
			length += ft_putchar(n + '0');
		else
			length += ft_putchar(n - 10 + 'a');
	}
	return (length);
}

/*
int	main(void)
{
	unsigned int	number;

	number = 3054464646;
	ft_print_hexlow(number);
	ft_putchar('\n');
	printf("%x", number);
	return (0);
}
*/
