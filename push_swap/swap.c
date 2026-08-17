/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdecarli <mdecarli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:04:02 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/10 18:01:25 by mdecarli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	third = second->next;
	*head = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
}

void	sa(t_stack **stack_a, int print)
{
	swap(stack_a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int print)
{
	swap(stack_b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		write(1, "ss\n", 3);
}
