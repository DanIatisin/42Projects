/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:55:16 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/31 10:53:58 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack *head)
{
	t_stack	*max_node;
	t_stack	*cur;

	if (!head)
		return (NULL);
	max_node = head;
	cur = head;
	while (cur)
	{
		if (cur->value > max_node->value)
			max_node = cur;
		cur = cur->next;
	}
	return (max_node);
}

static int	get_min_in_block(t_stack *head, int size)
{
	int	min;

	if (!head || size <= 0)
		return (0);
	min = head->value;
	while (head && size > 0)
	{
		if (head->value < min)
			min = head->value;
		head = head->next;
		size--;
	}
	return (min);
}

static int	get_max_in_block(t_stack *head, int size)
{
	int	max;

	if (!head || size <= 0)
		return (0);
	max = head->value;
	while (head && size > 0)
	{
		if (head->value > max)
			max = head->value;
		head = head->next;
		size--;
	}
	return (max);
}

int	find_pivot(t_stack *head, int size)
{
	long	min;
	long	max;

	min = get_min_in_block(head, size);
	max = get_max_in_block(head, size);
	return (min + (max - min) / 2);
}
