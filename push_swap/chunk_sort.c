/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:24:46 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/18 08:50:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_chunks(t_stack **stack_a, t_stack **stack_b, int limit, int chunk_size, int *i)
{
	if ((*stack_a)->index <= limit)
	{
		pb(stack_a, stack_b, 1);
		(*i)++;
	}
	else if ((*stack_a)->index <= limit + chunk_size)
	{
		pb(stack_a, stack_b, 1);
		rb(stack_b, 1);
		(*i)++;
	}
	else
		ra(stack_a, 1);
}

static void	push_chunks_b(t_stack **stack_a, t_stack **stack_b, int len)
{
	int limit;
	int chunk_size;
	int i;
	
	i = 0;
	if (len <= 100)
		chunk_size = len / 5;
	else 
		chunk_size = len / 11;
	limit = chunk_size;
	while (*stack_a)
	{
		process_chunks(stack_a, stack_b, limit, chunk_size, &i);
		if (i >= limit)
		{
			limit += chunk_size;
			if (limit > len)
				limit = len;
		}	
	}
}

static	int	get_max_pos(t_stack *stack)
{
	int max_val;
	int max_pos;
	int current_pos;
	t_stack *tmp;

	tmp = stack;
	max_val = tmp->index;
	max_pos = 0;
	current_pos = 0;
	printf("size of the stack is:%d\n", ft_lstsize_ps(tmp));
	while (tmp != NULL)
	{
		if (tmp->index > max_val)
		{
			max_val = tmp->index;
			max_pos = current_pos;
		}
			tmp = tmp->next;
			current_pos++;
	}
	printf("max_pos is: %d\n", max_pos);
	return (max_pos);	
}

static void	push_stack_a(t_stack **stack_a, t_stack **stack_b) 
{
	int max_pos;
	int size;
	int rotate;
	
	while (*stack_b)
	{
		max_pos = get_max_pos(*stack_b);
		size = ft_lstsize_ps(*stack_b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(stack_b, 1);
		}
		else
		{
			rotate = size - max_pos;
			while (rotate-- > 0)
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b, 1);
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int len;

	len = ft_lstsize_ps(*stack_a);
	printf("size of stack_a is: %d\n", len);
	if (is_sorted(*stack_a))
		return ;

	if (len <= 3)
	{
		sort_small_a(stack_a, len);
		return ;
	}
	
	push_chunks_b(stack_a, stack_b, len);
	printf("Stack_b -> \n");
	print_node(*stack_b);
	printf("Stack_a -> \n");
	print_node(*stack_a);
	push_stack_a(stack_a, stack_b);
	printf("Stack_a After: ->\n");
	print_node(*stack_a);
}