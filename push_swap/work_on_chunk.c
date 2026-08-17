int get_chunk_size(int min, int max, int chunk_number)
{
    int range_totale;
    int chunk_size;

    range_totale = (max - min) + 1;
    chunk_size = range_totale / chunk_number;
    if (chunk_size == 0)
        chunk_size = 1;
    return (chunk_size);
}

void    set_chunk_index(t_stack *stack, int min, int chunk_size, int chunk_number)
{
    while (stack)
    {
        stack->index = (stack->value - min) / chunk_size;
        if (stack->index >= chunk_number)
            stack->index = chunk_number - 1;
        stack = stack->next;
    }
}

t_stack *find_chunk_node(t_stack *stack, int chunk_index)
{
    t_stack *node;

    node = stack;
    while (node)
    {
        if (node->index == chunk_index)
            return (node);
        node = node->next;
    }
    return (NULL);
}