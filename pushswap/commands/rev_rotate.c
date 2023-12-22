/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:45:11 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/22 11:37:57 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"



void reverse_rotate(t_stack_node **stack)
{
    t_stack_node *last;
    t_stack_node *second_last;

    if (!(*stack) || !(*stack)->next)
        return;

    last = *stack;
    second_last = NULL;

    // Trouver le dernier et le deuxième dernier élément
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }

    // Faire la rotation inverse
    last->next = *stack;
    *stack = last;
    second_last->next = NULL;
}


void	rra(t_stack_node **a, bool print)
{
	reverse_rotate(a);
    if (print)
	    write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate(b);
    if (print)
	    write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
		reverse_rotate(a);
		reverse_rotate(b);
        if (print)
		    write(1, "rrr\n", 4);
}