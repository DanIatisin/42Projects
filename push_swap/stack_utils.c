/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:26:21 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/18 11:48:04 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew_ps(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new_node)
{
	t_stack	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		new_node->prev = NULL;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

int	ft_lstsize_ps(t_stack *stack)
{
	int		size;
	t_stack	*cur;
	
	cur = stack;
	size = 0;
	while (cur != NULL)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

// int	count_ops(int increment)
// {
// 	static int	ops = 0;

// 	if (increment)
// 		ops++;
// 	return (ops);
// }

// void	print_val_index(t_stack *stack)
// {
// 	t_stack *tmp;

// 	tmp = stack;
// 	while(tmp != NULL)
// 	{
// 		printf("value is: %d\n", tmp->value);
// 		printf("index is: %d\n", tmp->index);
// 		tmp = tmp->next;
// 	}
// }