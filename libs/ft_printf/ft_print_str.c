/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:03:14 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/29 13:22:09 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//#include <stdio.h>
int	ft_print_str(char *str)
{
	int	i;

	if (str == NULL)
	{
		str = "(null)";
	}
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	write(1, str, i);
	return (i);
}

/*int	main(void)
{
	ft_print_str("Idk what i am doing:( \n");
	printf("%s", "Idk what i am doing:(");
	return (0);
}
*/
