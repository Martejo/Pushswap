/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:33:42 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/08 16:53:30 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack_node *stack)
{
	size_t	size;
	
	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{	
		stack = stack->next;
		size++;
	}
	return (size);	
}

bool	stack_is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;
	int	max;

	if (!stack)
		return (NULL);
	max = stack->nbr;
	while (stack)
	{
		if (max < stack->nbr)
		{
			max_node = stack;
			max = stack->nbr;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min_node;
	int	min;

	if (!stack)
		return (NULL);
	min = stack->nbr;
	while (stack)
	{
		if (min > stack->nbr)
		{
			min_node = stack;
			min = stack->nbr;
		}
		stack = stack->next;
	}
	return (min_node);
}