/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdecarli <mdecarli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 13:46:25 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/07 16:49:46 by mdecarli         ###   ########.fr       */
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

	pos = 0;
	while (head)
	{
		if (head == min_node)
			return (pos);
		pos++;
		head = head->next;
	}
	return (-1);
}

int	is_sorted(t_stack *head)
{
	if (!head || !head->next)
		return (0);
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
