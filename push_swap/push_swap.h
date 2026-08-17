/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:14:07 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/17 11:08:30 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
//# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct	s_flags_ps
{
	int	bench;
	int flag;
}					t_flags_ps;

t_stack				*ft_lstnew_ps(int value);
void				ft_lstadd_back_ps(t_stack **stack, t_stack *new_node);
int					ft_lstsize_ps(t_stack *stack);
void				ft_free_stack(t_stack **stack);
t_stack				*find_min(t_stack *head);
int					get_position(t_stack *head, t_stack *min_node);
int					is_sorted(t_stack *head);
void				simple_sort(t_stack **stack_a, t_stack **stack_b);

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
int					find_pivot(t_stack *head, int size);
void				quick_sort_a(t_stack **a, t_stack **b, int size);

#endif