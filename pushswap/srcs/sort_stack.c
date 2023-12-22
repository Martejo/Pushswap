/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:39:22 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/22 11:41:45 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	set_stack(t_stack_node *a, t_stack_node *b, char stack_name)
{
	if (stack_name == 'b')
	{
		init_index(a);
		init_index(b);
		set_target_for_b(a, b);
	}
	else if (stack_name == 'a')
	{
		init_index(a);
		init_index(b);
		set_target_for_a(a, b);
		push_cost_analysis(a, b);
		find_cheapest(a);
	}
}

void	mv_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest;

	cheapest = get_cheapeast(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		rev_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	pb(a, b, true);
}

void	mv_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median == true)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median == true)
				rb(stack, true);
			else
				rrb(stack, true);
		}	
	}
}

void	sort_stack(t_stack_node **a , t_stack_node **b)
{
	size_t	len_a;

	len_a = stack_size(*a);
	if (len_a-- > 3 && !stack_is_sorted(*a))
		pb(a, b, true);
	if (len_a-- > 3 && !stack_is_sorted(*a))
		pb(a, b, true);
	while (len_a-- > 3 && !stack_is_sorted(*a))
	{
		set_stack(*a, *b, 'a');
		mv_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_stack(*a, *b, 'b');
		mv_b_to_a(a, b);
	}
	init_index(*a);
	min_on_top(a);
}