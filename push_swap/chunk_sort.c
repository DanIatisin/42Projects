void    smart_rotate_a(t_stack **stack_a, int pos)
{
    int size;
    int count;
    int count_back;

    size = ft_lstsize_ps(*stack_a);
    count = 0;
    count_back = 0;
    if (pos <= (size - pos))
    {
        while (count < pos)
        {
            ra(stack_a, 1);
            count++;
        }
    }
    else
    {
        while (count_back < (size - pos))
        {
            rra(stack_a, 1);
            count_back++;
        }
    }
}

void    smart_rotate_b(t_stack **stack_b, int pos)
{
    int size;
    int count;
    int count_back;

    size = ft_lstsize_ps(*stack_b);
    count = 0;
    count_back = 0;
    if (pos <= (size - pos))
    {
        while (count < pos)
        {
            rb(stack_b, 1);
            count++;
        }
    }
    else
    {
        while (count_back < (size - pos))
        {
            rrb(stack_b, 1);
            count_back++;
        }
    }
}

void    chunk_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
    int min;
    int max;
    int chunk_number;
    int chunk_size;

    size = ft_lstsize_ps(*a);
    get_min_max(*a, &min, &max);
    num_chunk = ft_sqrt(size);
    chunk_size = get_chunk_size(min, max, num_chunk);
    set_chunk_index(*a, min, chunk_size, num_chunk);
    empty_all_chunks(a, b, num_chunk);
    while (*b)
        pa(a, b, 1);
}

void empty_all_chunks(t_stack **a, t_stack **b, int num_chunk)
{
    int chunk_index;

    chunk_index = 0;
    while (chunk_index < num_chunk)
    {
        while (move_chunk_node(a, b, chunk_index))
            ;
        chunk_index++;
    }
}

int move_chunk_node(t_stack **a, t_stack **b, int chunk_index)
{
    t_stack *target;
    int pos_a, pos_b;

    target = find_chunk_node(*a, chunk_index);
    if (!target)
        return (0);
    pos_a = get_position_a(*a, chunk_index);
    smart_rotate_a(a, pos_a);
    pos_b = get_position_b(*b, (*a)->value);
    smart_rotate_b(b, pos_b);
    pb(a, b, 1);
    return (1);
}