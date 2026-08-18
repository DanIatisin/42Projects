/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:43:55 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/18 10:53:12 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Il principio di Quick Sort è dividere un blocco di elementi in due
sotto-blocchi usando un valore medio (il pivot):
I numeri più piccoli del pivot vanno in B.
I numeri più grandi o uguali al pivot restano in A.
Poi si fa la stessa cosa ricorsivamente su blocchi sempre più piccoli
fino ad arrivare a 1, 2 o 3 elementi.  */

#include "push_swap.h"

void	sort_small_a(t_stack **a, int size)
{
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a, 1);
	else if (size == 3)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, 1);
		if ((*a)->next->value > (*a)->next->next->value)
		{
			ra(a, 1);
			sa(a, 1);
			rra(a, 1);
		}
		if ((*a)->value > (*a)->next->value)
			sa(a, 1);
	}
}

void		quick_sort_b(t_stack **a, t_stack **b, int size);

void	quick_sort_a(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	pushed;
	int	pushed_back;
	int	count;

	if (size <= 3)
	{
		sort_small_a(a, size);
		return ;
	}
	pivot = find_pivot(*a, size);
	pushed = 0;
	pushed_back = 0;
	count = size;
	while (count-- > 0)
	{
		if ((*a)->value < pivot)
		{
			pb(a, b, 1);
			pushed++;
		}
		else
		{
			ra(a, 1);
			pushed_back++;
		}
	}
	while (pushed_back-- > 0)
		rra(a, 1);
	quick_sort_a(a, b, size - pushed);
	quick_sort_b(a, b, pushed);
}

void	quick_sort_b(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	pushed;
	int	pushed_back;
	int	count;

	if (size == 1)
	{
		pa(a, b, 1);
		return ;
	}
	if (size == 2)
	{
		if ((*b)->value < (*b)->next->value)
			sb(b, 1);
		pa(a, b, 1);
		pa(a, b, 1);
		return ;
	}
	pivot = find_pivot(*b, size);
	pushed = 0;
	pushed_back = 0;
	count = size;
	while (count-- > 0)
	{
		if ((*b)->value >= pivot)
		{
			pa(a, b, 1);
			pushed++;
		}
		else
		{
			rb(b, 1);
			pushed_back++;
		}
	}
	quick_sort_a(a, b, pushed);
	while (pushed_back-- > 0)
		rrb(b, 1);
	quick_sort_b(a, b, size - pushed);
}
