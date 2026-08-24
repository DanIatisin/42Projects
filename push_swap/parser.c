/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdecarli <mdecarli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:25:07 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/24 11:38:54 by mdecarli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_in_stack(t_stack **stack_a, char **argv, int offset)
{
	char	**tokens;
	int		i;

	while (argv[offset])
	{
		tokens = get_tokens(stack_a, argv[offset]);
		if (!tokens)
			return (0);
		i = 0;
		while (tokens[i])
		{
			if (!check_tokens(stack_a, tokens[i], tokens))
				return (0);
			i++;
		}
		free_tokens(tokens);
		offset++;
	}
	return (1);
}

int	parser(int argc, char **argv, t_flags_ps *f, t_stack **stack_a)
{
	int	offset;

	offset = validate_flag(f, argv, argc);
	if (offset == -1)
		return (0);
	if (!push_in_stack(stack_a, argv, offset))
		return (0);
	if (!control_dups(*stack_a))
	{
		ft_free_stack(stack_a);
		return (0);
	}
	return (1);
}
