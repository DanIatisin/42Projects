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

    stack_a = NULL;
    stack_b = NULL;
    parser(argc, argv, &f, &stack_a);
    normalize_stack(&stack_a);
    print_val_index(stack_a);
    // printf("sorting: \n");
    // print_node(stack_a);
    // printf("\n");
    chunk_sort(&stack_a, &stack_b);
    
    // printf("stack_a after is: \n");
    // print_node(stack_a);
    return (1);
}