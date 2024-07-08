/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:49:36 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/29 14:35:18 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_pointer(const void *ptr);
int	ft_print_di(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hexup(unsigned int n);
int	ft_print_hexlow(unsigned int n);
int	ft_printf(const char *__format, ...);

#endif