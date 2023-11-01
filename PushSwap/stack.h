#ifndef STACK_H
#define STACK_H

typedef struct      s_stack
{
    int             value;      // La valeur contenue dans le nœud
    struct s_stack   *next;      // Pointeur vers le nœud suivant dans la pile
}                   t_stack;

t_stack *ft_stack_push_front(t_stack *top, int value);
int find_size_stack(t_stack *stack);
void free_stack(t_stack *stack);
void print_data(t_stack *stack);

#endif 

