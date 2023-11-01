#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "stack.h"
#include <stdlib.h>


void    sa(t_stack **a); // swap les deux premiers éléments de 'a'
void    sb(t_stack **b); // swap les deux premiers éléments de 'b'
void    ss(t_stack **a, t_stack **b); //sa et sb en même temps
void    pa(t_stack **a, t_stack **b); //prend le premier élément en haut de b et le met au sommet de a.
void    pb(t_stack **a, t_stack **b); //prend le premier élément en haut de a et le met au sommet de b.
void ra(t_stack **a); //fait tourner tous les éléments de la pile a vers le haut de une case, le premier devient le dernier.
void rb(t_stack **b); //fait tourner tous les éléments de la pile b vers le haut de une case, le premier devient le dernier.
void rr(t_stack **a, t_stack **b); //ra et rb en même temps.
void rra(t_stack **a); //fait tourner tous les éléments de la pile a vers le bas de une case, le derniers devient le premier.
void rrb(t_stack **b); //fait tourner tous les éléments de la pile b vers le bas de une case, le derniers devient le premier.
void rrr(t_stack **a, t_stack **b); //rra et rrb en même temps

#endif