/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:33:42 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/21 18:45:29 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

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

t_stack_node *find_max(t_stack_node *stack)
{
    t_stack_node *max_node;
    int max;

    if (!stack)
        return NULL;

    max = INT_MIN;
    while (stack)
    {
        if (stack->nbr > max)
        {
            max_node = stack;
            max = stack->nbr;
        }
        stack = stack->next;
    }

    return max_node;
}


t_stack_node *find_min(t_stack_node *stack)
{
    t_stack_node *min_node;
    int min;

    if (!stack)
        return NULL;

    min = INT_MAX;
    while (stack)
    {
        if (stack->nbr < min)
        {
            min_node = stack;
            min = stack->nbr;
        }
        stack = stack->next;
	}
	return (min_node);
}
