/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:24:46 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/24 13:21:47 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_chunks(t_chunk_cs *cs)
{
	if ((*cs->stack_a)->index <= cs->limit)
	{
		pb(cs->stack_a, cs->stack_b, cs->f->print);
		cs->i++;
	}
	else if ((*cs->stack_a)->index <= cs->limit + cs->chunk_size)
	{
		pb(cs->stack_a, cs->stack_b, cs->f->print);
		rb(cs->stack_b, cs->f->print);
		cs->i++;
	}
	else
		ra(cs->stack_a, cs->f->print);
}

static void	push_chunks_b(t_chunk_cs *cs, int len)
{
	cs->i = 0;
	if (len <= 100)
		cs->chunk_size = len / 5;
	else
		cs->chunk_size = len / 11;
	if (cs->chunk_size < 1)
		cs->chunk_size = 1;
	cs->limit = cs->chunk_size;
	while (*cs->stack_a)
	{
		process_chunks(cs);
		if (cs->i >= cs->limit)
		{
			cs->limit += cs->chunk_size;
			if (cs->limit > len)
				cs->limit = len;
		}
	}
}

static int	get_max_pos(t_stack *stack)
{
	int		max_val;
	int		max_pos;
	int		current_pos;
	t_stack	*tmp;

	tmp = stack;
	max_val = tmp->index;
	max_pos = 0;
	current_pos = 0;
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
	return (max_pos);
}

static void	push_stack_a(t_chunk_cs *cs)
{
	int	max_pos;
	int	size;
	int	rotate;

	while (*cs->stack_b)
	{
		max_pos = get_max_pos(*cs->stack_b);
		size = ft_lstsize_ps(*cs->stack_b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(cs->stack_b, cs->f->print);
		}
		else
		{
			rotate = size - max_pos;
			while (rotate-- > 0)
				rrb(cs->stack_b, cs->f->print);
		}
		pa(cs->stack_a, cs->stack_b, cs->f->print);
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, t_flags_ps *f)
{
	t_chunk_cs	cs;
	int			len;

	len = ft_lstsize_ps(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (len <= 3)
	{
		sort_small_a(stack_a, len);
		return ;
	}
	cs.stack_a = stack_a;
	cs.stack_b = stack_b;
	cs.f = f;
	normalize_stack(stack_a);
	push_chunks_b(&cs, len);
	push_stack_a(&cs);
}
