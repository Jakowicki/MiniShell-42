/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:48:12 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/28 15:37:19 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_unsigned(unsigned int n)
{
	unsigned long	nb;
	int				length;

	length = 0;
	nb = n;
	if (nb > 9)
	{
		length += ft_print_unsigned(nb / 10);
		length += ft_print_unsigned(nb % 10);
	}
	else
	{
		length += ft_putchar(nb + '0');
	}
	return (length);
}
