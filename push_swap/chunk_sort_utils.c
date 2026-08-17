/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:24:59 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/17 11:32:39 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int lst_size)
{
	int	num;

	num = 0;
	while (num * num <= lst_size)
		num++;
	return (num);
}

void	get_min_max(t_stack *stack_a, int *min, int *max)
{
	*min = stack_a->value;
	*max = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->value < *min)
			*min = stack_a->value;
		if (stack_a->value > *max)
			*max = stack_a->value;
		stack_a = stack_a->next;
	}
	return ;
}

int	get_position_a(t_stack *stack_a, int chunk_index)
{
	int		pos;
	t_stack	*target;

	target = find_chunk_node(stack_a, chunk_index);
	pos = 0;
	while (stack_a)
	{
		if (stack_a == target)
			return (pos);
		pos++;
		stack_a = stack_a->next;
	}
	return (pos);
}

int	get_position_b(t_stack *stack_b, int value)
{
	int	pos;

	pos = 0;
	while (stack_b)
	{
		if (stack_b->value < value)
			return (pos);
		pos++;
		stack_b = stack_b->next;
	}
	return (pos);
}
