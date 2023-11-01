#include "instruction.h"
#include "stack.h"
#include "utils.h"
#include <stdio.h>


t_stack *create_stack(char **value)
{
    t_stack *stack = NULL;
    int boolean = 1;
    int data = 0;
    int i = 0;

    while (value[i])
        i++;
    i--;
    while (i >= 0)
    {
        data = my_atoi(value[i], &boolean);
        if (boolean != 1)
        {
            free_stack(stack);
            return (NULL);    
        }
        stack = ft_stack_push_front(stack, data);
        i--;
    }
    return (stack);
}

int is_sorted(t_stack *a)
{
    while (a && a->next) {
        if (a->value > a->next->value) return 0;
        a = a->next;
    }
    return 1;
}

int find_smallest_position(t_stack *a) 
{
    int pos = 0;
    int smallest_pos = 0;
    int smallest_val = a->value;
    a = a->next;
    while (a) {
        pos++;
        if (a->value < smallest_val) {
            smallest_val = a->value;
            smallest_pos = pos;
        }
        a = a->next;
    }
    return smallest_pos;
}

int list_length(t_stack *a)
{
    int len = 0;
    while (a)
    {
        len++;
        a = a->next;
    }
    return len;
}

int sort_stack(t_stack *a) 
{
    t_stack *b = NULL;
    int sol = 0;
    
    while (!is_sorted(a)) 
    {
        // Trouver la position du plus petit élément et le mettre en haut de a
        int pos = find_smallest_position(a);
        int len = list_length(a);

        if (pos <= len / 2)
        {
            while (pos-- > 0) 
            {
                ra(&a);
                printf("ra\n");
                sol++;
            }
        } 
        else 
        {
            while (pos++ < len) 
            {
                printf("rra\n");
                rra(&a);
                sol++;
            }
        }
        // Transférer le plus petit élément vers b
        pb(&a, &b);
        printf("pb\n");
        sol++;
    }
    // Transférer tous les éléments de b vers a
    while (b) 
    {
        pa(&a, &b);
        printf("pa\n");
        sol++;
    }
    return (sol);
}

int main(int argc, char **argv)
{
    t_stack *stack;

    if (argc > 1)
    {
        /*if (check_value_duplicate(&argv[1]) == 0)
        {
            printf("duplicata\n");
            return (0);
        }*/
        stack = create_stack(&argv[1]);
        printf("%d\n", sort_stack(stack));
        //print_data(stack);
        free_stack(stack);
    }
    return (0);
}