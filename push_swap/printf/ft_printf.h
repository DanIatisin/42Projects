/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:04:02 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/14 18:26:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	take_format(const char *format, va_list args);
int	ft_putchar(char c);
int	print_num(int val);
int	print_string(const char *s);
int	print_pointer(void *ptr);
int	print_unsigned(unsigned int val);
int	print_hex(unsigned long val, int uppercase);
int print_float(double val);

#endif