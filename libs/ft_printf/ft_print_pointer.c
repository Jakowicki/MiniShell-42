/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:30:23 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/29 13:22:27 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//#include <stdio.h>

static int	ft_write_hex(unsigned long long int value)
{
	char	hex_str[20];
	char	*hex_prefix;
	char	*hex_char;
	int		i;
	int		total_length;

	hex_prefix = "0x";
	hex_char = "0123456789abcdef";
	i = sizeof(hex_str) - 2;
	hex_str[i + 1] = '\0';
	if (value == 0)
	{
		hex_str[i] = '0';
		i--;
	}
	while (value > 0 && i >= 0)
	{
		hex_str[i] = hex_char[value % 16];
		value /= 16;
		i--;
	}
	write(1, hex_prefix, 2);
	write(1, &hex_str[i + 1], sizeof(hex_str) - i - 2);
	total_length = 2 + sizeof(hex_str) - i - 2;
	return (total_length);
}

int	ft_print_pointer(const void *ptr)
{
	unsigned long long int	ptr_value;
	int						length;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ptr_value = (unsigned long long int)ptr;
	length = ft_write_hex(ptr_value);
	return (length);
}

/*
int	main(void)
{
	ft_print_pointer("0");
	printf("\n%p", "0");
	return (0);
}
*/