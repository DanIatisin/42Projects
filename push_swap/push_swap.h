/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:14:07 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/14 13:32:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_flags_ps
{
	int	bench;
	int mode;
}					t_flags_ps;

t_stack				*ft_lstnew_ps(int value);
void				ft_lstadd_back_ps(t_stack **stack, t_stack *new_node);
int					ft_lstsize_ps(t_stack *stack);
void				ft_free_stack(t_stack **stack);

void				sa(t_stack **stack_a, int print);
void				sb(t_stack **stack_b, int print);
void				ss(t_stack **stack_a, t_stack **stack_b, int print);
void				pa(t_stack **stack_a, t_stack **stack_b, int print);
void				pb(t_stack **stack_a, t_stack **stack_b, int print);
void				ra(t_stack **stack_a, int print);
void				rb(t_stack **stack_b, int print);
void				rr(t_stack **stack_a, t_stack **stack_b, int print);
void				rra(t_stack **stack_a, int print);
void				rrb(t_stack **stack_b, int print);
void				rrr(t_stack **stack_a, t_stack **stack_b, int print);
float				compute_disorder_ps(t_stack *head, int mistake, int total_pairs);
void 				print_stack(t_stack *head);
int					check_number(char *s);
int					match_flags(t_flags_ps *f, char *s);
int					validate_flag(t_flags_ps *f, char **argv, int argc);
int					control_dups(t_stack *stack_a);
int					push_in_stack(t_stack **stack_a, char **argv, int offset);
int					parser(int argc, char **argv, t_flags_ps *f, t_stack **stack_a);

#endif