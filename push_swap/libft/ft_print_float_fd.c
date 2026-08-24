/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdecarli <mdecarli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:55:41 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/24 11:55:42 by mdecarli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_float_fd(double value, int decimals, int fd)
{
	long	int_part;
	long	frac_part;
	long	mult;

	if (value < 0)
	{
		ft_putstr_fd("-", fd);
		value = -value;
	}
	mult = 1;
	while (decimals-- > 0)
		mult *= 10;
	int_part = (long)(value * mult + 0.5) / mult;
	frac_part = (long)(value * mult + 0.5) % mult;
	ft_putnbr_fd((int)int_part, fd);
	ft_putstr_fd(".", fd);
	mult /= 10;
	while (mult > 1 && frac_part < mult)
	{
		ft_putstr_fd("0", fd);
		mult /= 10;
	}
	ft_putnbr_fd((int)frac_part, fd);
}
