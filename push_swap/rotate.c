/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdecarli <mdecarli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:02:14 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/10 18:01:07 by mdecarli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	last = first;
	while (last->next)
		last = last->next;
	*head = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int print)
{
	rotate(stack_b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		write(1, "rr\n", 3);
}
