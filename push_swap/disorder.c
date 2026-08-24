/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:42:11 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/24 13:21:38 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder_ps(t_stack *head)
{
	int		mistake;
	int		total_pairs;
	t_stack	*node;

	if (ft_lstsize_ps(head) < 2)
		return (0);
	mistake = 0;
	total_pairs = 0;
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

static void	choose_strategy(t_stack **stack_a, t_stack **stack_b, t_flags_ps *f,
		int size)
{
	float	disorder;

	disorder = compute_disorder_ps(*stack_a);
	if (f->mode == 1 || (f->mode == 0 && disorder < 0.2f))
	{
		f->complexity = 0;
		simple_sort(stack_a, stack_b, f);
	}
	else if (f->mode == 2 || (f->mode == 0 && disorder <= 0.5f))
	{
		f->complexity = 1;
		chunk_sort(stack_a, stack_b, f);
	}
	else
	{
		f->complexity = 2;
		quick_sort_a(stack_a, stack_b, size);
	}
}

void	custom_adaptive(t_stack **stack_a, t_stack **stack_b, t_flags_ps *f)
{
	int	size;

	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	size = ft_lstsize_ps(*stack_a);
	if (size <= 3)
	{
		simple_sort(stack_a, stack_b, f);
		return ;
	}
	choose_strategy(stack_a, stack_b, f, size);
}

// da aggiungere algoritmo n2 nel ciclo del custom_adaptive

/*	creare un blocco di elementi in due sotto
	- blocchi usando un valore medio(il pivot) :
	I numeri più piccoli del pivot vanno in B.I
	numeri più grandi o uguali al pivot restano in A.
	Poi si fa la stessa cosa ricorsivamente su blocchi
	sempre più piccoli fino ad arrivare a 1,
	2 o 3 elementi.*/
