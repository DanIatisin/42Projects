/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:27:41 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/19 11:27:50 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*node_to_push;

	if (!stack_b || !*stack_b)
		return ;
	node_to_push = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	node_to_push->next = *stack_a;
	node_to_push->prev = NULL;
	if (*stack_a)
		(*stack_a)->prev = node_to_push;
	*stack_a = node_to_push;
	count_op(3);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*node_to_push;

	if (!stack_a || !*stack_a)
		return ;
	node_to_push = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	node_to_push->next = *stack_b;
	node_to_push->prev = NULL;
	if (*stack_b)
		(*stack_b)->prev = node_to_push;
	*stack_b = node_to_push;
	count_op(4);
	if (print)
		write(1, "pb\n", 3);
}
