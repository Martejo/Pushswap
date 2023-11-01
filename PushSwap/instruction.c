#include "instruction.h"

void    sa(t_stack **a)
{
    int     tmp;

    if (*a && (*a)->next)
    {
        tmp = (*a)->value;
        (*a)->value = (*a)->next->value;
        (*a)->next->value = tmp;
    }
}

void    sb(t_stack **b)
{
    int     tmp;

    if (*b && (*b)->next)
    {
        tmp = (*b)->value;
        (*b)->value = (*b)->next->value;
        (*b)->next->value = tmp;
    }
}

void    ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
}

void    pa(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!(*b))
        return;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
}

void    pb(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!(*a))
        return;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
}

void ra(t_stack **a)
{
    t_stack *first;
    t_stack *current;

    if ((*a) == NULL || (*a)->next == NULL)
        return;

    first = *a; // Sauvegarder le premier élément
    *a = first->next;   // Le deuxième élément devient le premier

    current = *a;
    while (current->next != NULL) 
    {
        current = current->next; // Se déplacer jusqu'à la fin de la pile
    }
    current->next = first;      // Le premier élément devient le dernier
    first->next = NULL;         // Le dernier élément pointe vers NULL
}

void rb(t_stack **b)
{
    t_stack *first;
    t_stack *current;

    if ((*b) == NULL || (*b)->next == NULL)
        return;

    first = *b; // Sauvegarder le premier élément
    *b = first->next;   // Le deuxième élément devient le premier

    current = *b;
    while (current->next != NULL) 
    {
        current = current->next; // Se déplacer jusqu'à la fin de la pile
    }
    current->next = first;      // Le premier élément devient le dernier
    first->next = NULL;         // Le dernier élément pointe vers NULL
}

void    rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
}

void rra(t_stack **a)
{
    t_stack *prev;
    t_stack *current;

    if (*a == NULL || (*a)->next == NULL) // Si la pile est vide ou contient seulement un élément
        return;
    prev = NULL;
    current = (*a);
    // Se déplacer jusqu'à l'avant-dernier élément de la pile
    while (current->next != NULL) 
    {
        prev = current;
        current = current->next;
    }

    // L'avant-dernier élément pointe maintenant vers NULL
    prev->next = NULL;
    // Le dernier élément pointe vers le premier
    current->next = *a;
    // Le dernier élément devient le premier
    *a = current;
}

void rrb(t_stack **b)
{
    t_stack *prev;
    t_stack *current;

    if (*b == NULL || (*b)->next == NULL) // Si la pile est vide ou contient seulement un élément
        return;
    prev = NULL;
    current = (*b);
    // Se déplacer jusqu'à l'avant-dernier élément de la pile
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    // L'avant-dernier élément pointe maintenant vers NULL
    prev->next = NULL;
    // Le dernier élément pointe vers le premier
    current->next = *b;
    // Le dernier élément devient le premier
    *b = current;
}

void    rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
}



