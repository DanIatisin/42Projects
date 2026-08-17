/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 13:46:25 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/17 19:25:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *head)
{
	t_stack	*min_node;
	t_stack	*cur;

	if (!head)
		return (NULL);
	min_node = head;
	cur = head;
	while (cur)
	{
		if (cur->value < min_node->value)
			min_node = cur;
		cur = cur->next;
	}
	return (min_node);
}

int	get_position(t_stack *head, t_stack *min_node)
{
	int	pos;

	if (!head || !min_node)
		return (-1);
	pos = 0;
	while (head)
	{
		if (head == min_node || head->value == min_node->value)
			return (pos);
		pos++;
		head = head->next;
	}
	return (-1);
}

int	is_sorted(t_stack *head)
{
	if (!head || !head->next)
		return (1);
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

static void	push_min_to_top(t_stack **stack_a)
{
	t_stack	*min;
	int		pos;
	int		size;

	if (!stack_a || !*stack_a)
		return ;
	min = find_min(*stack_a);
	if (!min)
		return ;
	pos = get_position(*stack_a, min);
	size = ft_lstsize_ps(*stack_a);
	if (pos == -1)
		return ;
	if (pos <= size / 2)
	{
		while (*stack_a != min)
			ra(stack_a, 1);
	}
	else
	{
		while (*stack_a != min)
			rra(stack_a, 1);
	}
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	while (*stack_a)
	{
		push_min_to_top(stack_a);
		pb(stack_a, stack_b, 1);
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b, 1);
	}
}
