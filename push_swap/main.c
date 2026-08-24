/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 13:30:27 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/24 13:31:44 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_flags_ps	f;
	float		disorder;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	if (!parser(argc, argv, &f, &a))
	{
		write(2, "Error\n", 6);
		ft_free_stack(&a);
		ft_free_stack(&b);
		return (0);
	}
	f.print = 1;
	disorder = compute_disorder_ps(a);
	custom_adaptive(&a, &b, &f);
	if (f.bench)
		benchmode(disorder, count_op(-1), &f);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
