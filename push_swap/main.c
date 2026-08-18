#include "push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack *stack, char *name)
{
	printf("Pila %s: ", name);
	if (!stack)
	{
		printf("(vuota)\n");
		return ;
	}
	while (stack)
	{
		printf("%d ", stack->value);		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	ft_lstadd_back_ps(&a, ft_lstnew_ps(42));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(-10));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(5));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(0));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(12));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(-2));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(8));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(3));
	printf("=== PRIMA DEL QUICK SORT ===\n");
	print_stack(a, "A");
	print_stack(b, "B");
	printf("Ordinata? %s\n\n", is_sorted(a) ? "SI" : "NO");
	printf("=== MOSSE ESEGUITE ===\n");
	quick_sort_a(&a, &b, ft_lstsize_ps(a));
	printf("\n=== DOPO IL QUICK SORT ===\n");
	print_stack(a, "A");
	print_stack(b, "B");
	printf("Ordinata? %s\n", is_sorted(a) ? "SI" : "NO");
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}

/*
#include "push_swap.h"
#include <stdlib.h>
static void	print_stack(t_stack *stack, char *name)
{
	printf("Pila %s: ", name);
	if (!stack)
	{
		printf("(vuota)\n");
		return ;
	}
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;

	ft_lstadd_back_ps(&a, ft_lstnew_ps(5));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(-2));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(42));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(0));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(12));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(-10));

	printf("=== PRIMA DELL'ORDINAMENTO ===\n");
	print_stack(a, "A");
	print_stack(b, "B");
	printf("Ordinata? %s\n\n", is_sorted(a) ? "SI" : "NO");

	printf("=== MOSSE ESEGUITE ===\n");
	simple_sort(&a, &b);

	printf("\n=== DOPO L'ORDINAMENTO ===\n");
	print_stack(a, "A");
	print_stack(b, "B");
	printf("Ordinata? %s\n", is_sorted(a) ? "SI" : "NO");

	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}*/