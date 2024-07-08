/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:53:21 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/29 14:42:22 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(char letter, va_list args)
{
	if (letter == '%')
		return (write(1, "%", 1));
	else if (letter == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (letter == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (letter == 'p')
		return (ft_print_pointer(va_arg(args, const void *)));
	else if (letter == 'd')
		return (ft_print_di(va_arg(args, int)));
	else if (letter == 'i')
		return (ft_print_di(va_arg(args, int)));
	else if (letter == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (letter == 'x')
		return (ft_print_hexlow(va_arg(args, unsigned int)));
	else if (letter == 'X')
		return (ft_print_hexup(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *__format, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!__format)
		return (0);
	i = 0;
	len = 0;
	va_start(args, __format);
	while (__format[i])
	{
		if (__format[i] == '%')
		{
			i++;
			len += ft_conversion(__format[i], args);
		}
		else
			len += write(1, &__format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

// #include "ft_printf.h"
// #include <stdio.h>

// int main() {
//     int num = 42;
//     unsigned int unum = 42;
//     char *str = "Hello, World!";
//     char ch = 'A';
//     void *ptr = &num;

//     // Test printing a string
//     ft_printf("String: %s\n", str);

//     // Test printing characters
//     ft_printf("Character: %c\n", ch);

//     // Test printing decimal and integer
//     ft_printf("Decimal: %d\n", num);
//     ft_printf("Integer: %i\n", num);

//     // Test printing unsigned integer
//     ft_printf("Unsigned: %u\n", unum);

//     // Test printing hexadecimal (lowercase and uppercase)
//     ft_printf("Hex (lowercase): %x\n", unum);
//     ft_printf("Hex (uppercase): %X\n", unum);

//     // Test printing pointer
//     ft_printf("Pointer: %p\n", ptr);

//     // Test printing percent sign
//     ft_printf("Percent: %%\n");

//     return (0);
// }