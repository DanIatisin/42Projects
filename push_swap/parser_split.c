/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdecarli <mdecarli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:44:47 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/24 11:45:32 by mdecarli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	is_all_spaces(char *s)
{
	while (*s)
	{
		if (*s != ' ')
			return (0);
		s++;
	}
	return (1);
}

int	check_tokens(t_stack **stack_a, char *token, char **tokens)
{
	t_stack	*node;

	if (!check_number(token))
	{
		free_tokens(tokens);
		ft_free_stack(stack_a);
		return (0);
	}
	node = ft_lstnew_ps(ft_atoi(token));
	if (!node)
	{
		free_tokens(tokens);
		ft_free_stack(stack_a);
		return (0);
	}
	ft_lstadd_back_ps(stack_a, node);
	return (1);
}

char	**get_tokens(t_stack **stack_a, char *arg)
{
	char	**tokens;

	if (!*arg || is_all_spaces(arg))
	{
		ft_free_stack(stack_a);
		return (NULL);
	}
	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
	{
		free_tokens(tokens);
		ft_free_stack(stack_a);
		return (NULL);
	}
	return (tokens);
}
