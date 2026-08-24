/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:43:55 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/24 13:28:28 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_a(t_stack **a, t_stack **b, int pivot, t_part *p)
{
	int	size;

	size = p->size;
	while (size-- > 0)
	{
		if ((*a)->value < pivot)
		{
			pb(a, b, 1);
			p->pushed++;
		}
		else
		{
			ra(a, 1);
			p->pushed_back++;
		}
	}
}

void	partition_b(t_stack **a, t_stack **b, int pivot, t_part *p)
{
	int	size;

	size = p->size;
	while (size-- > 0)
	{
		if ((*b)->value >= pivot)
		{
			pa(a, b, 1);
			p->pushed++;
		}
		else
		{
			rb(b, 1);
			p->pushed_back++;
		}
	}
}

static void	quick_sort_b(t_stack **a, t_stack **b, int size)
{
	t_part	p;

	if (size == 1)
		return (pa(a, b, 1));
	if (size == 2)
	{
		if ((*b)->value < (*b)->next->value)
			sb(b, 1);
		pa(a, b, 1);
		return (pa(a, b, 1));
	}
	p.size = size;
	p.pushed = 0;
	p.pushed_back = 0;
	partition_b(a, b, find_pivot(*b, size), &p);
	quick_sort_a(a, b, p.pushed);
	while (p.pushed_back-- > 0)
		rrb(b, 1);
	quick_sort_b(a, b, size - p.pushed);
}

void	quick_sort_a(t_stack **a, t_stack **b, int size)
{
	t_part	p;

	if (size <= 3)
		return (sort_small_a(a, size));
	p.size = size;
	p.pushed = 0;
	p.pushed_back = 0;
	partition_a(a, b, find_pivot(*a, size), &p);
	while (p.pushed_back-- > 0)
		rra(a, 1);
	quick_sort_a(a, b, size - p.pushed);
	quick_sort_b(a, b, p.pushed);
}
