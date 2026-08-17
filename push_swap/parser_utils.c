/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:25:16 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/17 11:25:43 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *s)
{
	int	i;
	int	len;
	int	sign;

	if (!s || !*s)
		return (0);
	sign = '+';
	if (*s == '+' || *s == '-')
		sign = *s++;
	len = (ft_strlen(s));
	if (!len || len > 10)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i++]))
			return (0);
	}
	if (len == 10 && sign == '+' && ft_strncmp(s, "2147483647", 10) > 0)
		return (0);
	if (len == 10 && sign == '-' && ft_strncmp(s, "2147483648", 10) > 0)
		return (0);
	return (1);
}

int	match_flags(t_flags_ps *f, char *s)
{
	if (!ft_strncmp(s, "--bench", 8) && f->bench == 0)
		f->bench = 1;
	else if (!ft_strncmp(s, "--adaptive", 11) && f->mode == -1)
		f->mode = 0;
	else if (!ft_strncmp(s, "--simple", 9) && f->mode == -1)
		f->mode = 1;
	else if (!ft_strncmp(s, "--medium", 9) && f->mode == -1)
		f->mode = 2;
	else if (!ft_strncmp(s, "--complex", 10) && f->mode == -1)
		f->mode = 3;
	else
		return (0);
	return (1);
}

int	validate_flag(t_flags_ps *f, char **argv, int argc)
{
	int	i;

	f->bench = 0;
	f->mode = -1;
	i = 1;
	while (i < argc && !check_number(argv[i]))
	{
		if (!match_flags(f, argv[i]))
			return (-1);
		i++;
	}
	if (f->mode == -1)
		f->mode = 0;
	if (i == argc)
		return (-1);
	return (i);
}

int	control_dups(t_stack *stack_a)
{
	t_stack	*head;
	t_stack	*node;

	head = stack_a;
	while (head != NULL)
	{
		node = head->next;
		while (node != NULL)
		{
			if (head->value == node->value)
				return (0);
			node = node->next;
		}
		head = head->next;
	}
	return (1);
}
