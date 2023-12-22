/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:42:29 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/22 11:42:29 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	*get_cheapeast(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b, true);
	init_index(*a);
	init_index(*b);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b, true);
	init_index(*a);
	init_index(*b);
}

void min_on_top(t_stack_node **a)
{
    while (1)
    {
        t_stack_node *minNode = find_min(*a);

        if (!minNode) // Si la liste est vide, il n'y a rien à faire.
            return;

        if ((*a)->nbr == minNode->nbr) // Si le minimum est déjà en haut, nous avons terminé.
            break;

        // Le minimum n'est pas en haut, donc nous devons décider d'utiliser ra ou rra.
        if (minNode->above_median)
            ra(a, true);
        else
            rra(a, true);
    }
}