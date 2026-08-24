/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:14:07 by mdecarli          #+#    #+#             */
/*   Updated: 2026/08/24 13:29:31 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "push_swap.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_flags_ps
{
	int				bench;
	int				mode;
	int				print;
	int				complexity;
}					t_flags_ps;

typedef struct s_part
{
	int				size;
	int				pushed;
	int				pushed_back;
}					t_part;

typedef struct s_chunk_cs
{
	t_stack			**stack_a;
	t_stack			**stack_b;
	t_flags_ps		*f;
	int				limit;
	int				chunk_size;
	int				i;
}					t_chunk_cs;

void				partition_a(t_stack **a, t_stack **b, int pivot, t_part *p);
void				partition_b(t_stack **a, t_stack **b, int pivot, t_part *p);

t_stack				*ft_lstnew_ps(int value);
void				ft_lstadd_back_ps(t_stack **lst, t_stack *new_node);
int					ft_lstsize_ps(t_stack *stack);
void				ft_free_stack(t_stack **stack);
t_stack				*find_min(t_stack *head);
int					get_position(t_stack *head, t_stack *min_node);
int					is_sorted(t_stack *head);
void				simple_sort(t_stack **stack_a, t_stack **stack_b,
						t_flags_ps *f);

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
void				sort_small_a(t_stack **a, int size);

// Funzioni usati dal parser:
int					check_number(char *s);
int					match_flags(t_flags_ps *f, char *s);
int					validate_flag(t_flags_ps *f, char **argv, int argc);
int					control_dups(t_stack *stack_a);
int					push_in_stack(t_stack **stack_a, char **argv, int offset);
int					parser(int argc, char **argv, t_flags_ps *f,
						t_stack **stack_a);
int					is_known_flag(char *s);

// funzioni da parser_split:
void				free_tokens(char **tokens);
int					is_all_spaces(char *s);
int					check_tokens(t_stack **stack_a, char *token, char **tokens);
char				**get_tokens(t_stack **stack_a, char *arg);

void				normalize_stack(t_stack **stack_a);
void				chunk_sort(t_stack **stack_a, t_stack **stack_b,
						t_flags_ps *f);

void				print_node(t_stack *head);
void				custom_adaptive(t_stack **stack_a, t_stack **stack_b,
						t_flags_ps *f);
float				compute_disorder_ps(t_stack *head);
int					*count_op(int k);

void				benchmode(float d, int *n, t_flags_ps *f);

#endif