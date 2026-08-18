#include "push_swap.h"

void    print_node(t_stack *head)
{
    t_stack *current;

    current = head;
    while(current != NULL)
    {
        printf("%d\n", current->value);
        current = current-> next;
    }
}

int main(int argc, char **argv)
{

    //compila con: 
    // gcc *.c -Iprintf -Ilibft -Lprintf -lftprintf -Llibft -lft -o test
    t_stack *stack_a;
    t_stack *stack_b;
    t_flags_ps f;
    
    if (argc < 2)
        return (0);

    stack_a = NULL;
    stack_b = NULL;
    
    if (!parser(argc, argv, &f, &stack_a))
    {
        printf("Error");
        return (0);
    }
    normalize_stack(&stack_a);
    // print_val_index(stack_a);
    // printf("before sorting: \n");
    // print_node(stack_a);
    // printf("\n");
    custom_adaptive(&stack_a, &stack_b, &f);
    chunk_sort(&stack_a, &stack_b);
    
    printf("stack_a after is: \n");
    print_node(stack_a);
    return (1);
}