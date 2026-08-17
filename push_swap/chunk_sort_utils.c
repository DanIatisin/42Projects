/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:24:59 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/17 19:10:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_stack(t_stack **stack_a)
{
	int len;
	int *array;
	int i;
	t_stack *tmp;

	len = ft_lstsize_ps(*stack_a);
	array = malloc(sizeof(int) * len);
	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		array[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	sort_array(array, len);
	set_index(*stack_a, array, len);
	free(array);
}

void	sort_array(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
}

void	set_index(t_stack *stack, int *tab, int size)
{
	int i;
	
	while (stack)
	{
		i = 0;
		while (i < size && stack->value != tab[i])
			i++;
		stack->index = i;
		stack = stack->next;
	}
}