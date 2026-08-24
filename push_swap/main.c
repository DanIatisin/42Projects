#include "push_swap.h"

int main (int argc, char **argv)
{

    t_stack     *a;
    t_stack     *b;
    t_flags_ps  f;
    float       disorder;

    if (argc < 2)
        return (1);
    a = NULL;
    b = NULL;
    if (!a || !b || !parser(argc, argv, &f, &a))
    {
        write(2, "Error\n", 6);
        ft_free_stack(&a);
        ft_free_stack(&b);
        // return (ft_free_stack(a), ft_free_stack(b), write (2, "Error\n", 6, 0))
        return (0);
    }
    disorder = compute_disorder_ps(a);
    custom_adaptive(&a, &b, &f);
    if (f.bench)
        benchmark(....);
    ft_free_stack(&a);
    ft_free_stack(&b);
    return (0);
}