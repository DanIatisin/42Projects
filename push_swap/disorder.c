/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:42:11 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/13 10:45:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder_ps(t_stack *head, int mistake, int total_pairs)
{
	t_stack	*node;

	if (ft_lstsize_ps(head) < 2)
		return (0);
	while (head != NULL)
	{
		node = head->next;
		while (node != NULL)
		{
			total_pairs++;
			if (head->value > node->value)
				mistake++;
			node = node->next;
		}
		head = head->next;
	}
	return ((float)mistake / total_pairs);
}
