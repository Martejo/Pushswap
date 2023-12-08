/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:45:29 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/08 17:01:40 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node *max;

	if (!stack)
		return ;
	max = find_max(*stack);
	if (*stack == max)
		ra(stack); // plus print 
	else if ((*stack)->next == max)
		rra(stack); // + print
	if ((*stack)->nbr > (*stack)->next->nbr) // a degager si inutile
		sa(stack); //+print
}