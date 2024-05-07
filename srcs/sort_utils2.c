/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:42:29 by gemartel          #+#    #+#             */
/*   Updated: 2024/01/03 10:09:12 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	*get_cheapeast(t_stack *stack)
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

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b, true);
	init_index(*a);
	init_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b, true);
	init_index(*a);
	init_index(*b);
}

void	min_on_top(t_stack **a)
{
	t_stack	*min_node;

	while (1)
	{
		min_node = find_min(*a);
		if (!min_node)
			return ;
		if ((*a)->nbr == min_node->nbr)
			break ;
		if (min_node->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}
