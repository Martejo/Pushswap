/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:10:48 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/08 17:33:10 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	int	target;

	target = INT_MIN;
	if (!a || !b)
		return ;
	while (a)
	{
		current_b = b;
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

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	int	target;

	target = INT_MAX;
	if (!a || !b)
		return ;
	while (b)
	{
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