/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 13:26:33 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/24 13:26:39 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bench_ps(int *n)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(n[0], 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(n[1], 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(n[2], 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(n[3], 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(n[4], 2);
	ft_putchar_fd('\n', 2);
}

static void	bench_r(int *n)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(n[5], 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(n[6], 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(n[7], 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(n[8], 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(n[9], 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(n[10], 2);
	ft_putchar_fd('\n', 2);
}

void	benchmode(float d, int *n, t_flags_ps *f)
{
	char	*strategy[4];
	char	*complexity[3];

	strategy[0] = "Adaptive";
	strategy[1] = "Simple";
	strategy[2] = "Medium";
	strategy[3] = "Complex";
	complexity[0] = "O(n²)";
	complexity[1] = "O(n√n)";
	complexity[2] = "O(n log n)";
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_print_float_fd(d * 100, 2, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd(strategy[f->mode], 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(complexity[f->complexity], 2);
	ft_putstr_fd("\n[bench] total ops: ", 2);
	ft_putnbr_fd(n[11], 2);
	ft_putchar_fd('\n', 2);
	bench_ps(n);
	bench_r(n);
}
