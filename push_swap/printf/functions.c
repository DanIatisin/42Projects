/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:36:46 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/17 11:21:09 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(const char *s)
{
	int	char_count;

	char_count = 0;
	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		char_count += ft_putchar(*s);
		s++;
	}
	return (char_count);
}

int	print_unsigned(unsigned int val)
{
	int	char_count;

	char_count = 0;
	if (val >= 10)
	{
		char_count += print_unsigned(val / 10);
	}
	char_count += ft_putchar('0' + (val % 10));
	return (char_count);
}

int	print_num(int val)
{
	int	char_count;

	char_count = 0;
	if (val < 0)
	{
		ft_putchar('-');
		char_count++;
		char_count += print_unsigned((unsigned int)(-val));
	}
	else
	{
		char_count += print_unsigned((unsigned int)val);
	}
	return (char_count);
}

int	print_hex(unsigned long val, int uppercase)
{
	int		char_count;
	char	digit;

	char_count = 0;
	if (val >= 16)
	{
		char_count += print_hex((val / 16), uppercase);
	}
	if ((val % 16) < 10)
	{
		digit = '0' + (val % 16);
	}
	else
	{
		if (uppercase)
			digit = 'A' + ((val % 16) - 10);
		else
			digit = 'a' + ((val % 16) - 10);
	}
	char_count += ft_putchar(digit);
	return (char_count);
}

int	print_pointer(void *ptr)
{
	int				char_count;
	unsigned long	address;

	char_count = 0;
	address = (unsigned long)ptr;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putchar('0');
	ft_putchar('x');
	char_count += 2;
	char_count += print_hex(address, 0);
	return (char_count);
}
