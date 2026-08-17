/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:25:07 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/17 11:25:08 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_in_stack(t_stack **stack_a, char **argv, int offset)
{
	t_stack	*node;

	while (argv[offset])
	{
		if (!check_number(argv[offset]))
		{
			ft_free_stack(stack_a);
			return (0);
		}
		node = ft_lstnew_ps(ft_atoi(argv[offset]));
		if (!node)
		{
			ft_free_stack(stack_a);
			return (0);
		}
		ft_lstadd_back_ps(stack_a, node);
		offset++;
	}
	return (1);
}

int	parser(int argc, char **argv, t_flags_ps *f, t_stack **stack_a)
{
	int	offset;

	offset = validate_flag(f, argv, argc);
	if (offset == -1)
		return (0);
	if (!push_in_stack(stack_a, argv, offset))
		return (0);
	if (!control_dups(*stack_a))
	{
		ft_free_stack(stack_a);
		return (0);
	}
	return (1);
}
