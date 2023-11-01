#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

t_stack    *ft_create_elem(int data)
{
    t_stack *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = data;
    node->next = NULL;
    return (node);
}

t_stack *ft_stack_push_front(t_stack *top, int value)
{
    t_stack *node;

    node = ft_create_elem(value);
    if (!node)
        return (top); // Si malloc échoue, retournez simplement le top original bien faire la gestion d'erreur 
    node->next = top;
    return node;
}

int find_size_stack(t_stack *stack)
{
    int count;
    t_stack *tmp;

    tmp = stack;
    count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

void free_stack(t_stack *stack)
{
    t_stack *tmp;

    while (stack != NULL)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

void print_data(t_stack *stack)
{
    t_stack *current;

    current = stack;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}
