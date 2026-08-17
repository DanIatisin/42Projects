/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:20:31 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/17 11:20:51 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_float(double val)
{
	int		char_count;
	double	resto;

	char_count = 0;
	resto = val * 10 + 0.5;
	if (resto >= 10)
	{
		char_count += print_num((int)val + 1);
		char_count += ft_putchar('.');
		char_count += print_num(0);
	}
	else
	{
		char_count += print_num((int)val);
		char_count += ft_putchar('.');
		char_count += print_num((int)resto);
	}
	return (char_count);
}
