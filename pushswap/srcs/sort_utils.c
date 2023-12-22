/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:10:48 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/21 18:37:40 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	set_target_for_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	int	target;

	
	if (!a || !b)
		return ;
	while (a)
	{
		current_b = b;
		target = INT_MIN;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > target)
			{
				target = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (target == INT_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	set_target_for_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	int	target;

	
	if (!a || !b)
		return ;
	while (b)
	{
		target = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < target)
			{
				target = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (target == INT_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_index(t_stack_node *stack)
{
	int	median;
	int	i;

	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	push_cost_analysis(t_stack_node *a, t_stack_node  *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);

	while (a)
	{
		a->push_cost = a->index;
		if (a->above_median == false) // si en dessous de median
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median == true)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	find_cheapest(t_stack_node *stack)
{
	long	cheapest;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}




