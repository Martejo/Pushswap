/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:45:29 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/22 11:41:12 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node *max;

	if (!stack)
		return ;
	max = find_max(*stack);
	if (*stack == max)
		ra(stack, true); // plus print 
	else if ((*stack)->next == max)
		rra(stack, true); // + print
	if ((*stack)->nbr > (*stack)->next->nbr) //Check if the bottom node is the biggest, but the top node is higher than the second node
		sa(stack, true); //I
}