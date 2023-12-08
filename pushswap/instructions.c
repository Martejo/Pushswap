/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:27:17 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/08 12:52:32 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*push_node(t_stack_node **stack1, t_stack_node **stack2)
{
	t_stack_node	*tmp;

	if (!(*stack2))
		return ;
	tmp = (*stack2);
	(*stack2) = (*stack2)->next;
	tmp->next = (*stack1);
	(*stack1) = tmp;
}

void	swap_node(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap_node(a);
	swap_node(b);
}

void	*rotate_stack(t_stack_node **stack)
{
	t_stack_node *first;
	t_stack_node *current;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	current = (*stack);
	(*stack) = first->next;
	while (current->next != NULL)
	{	
		current = current->next;
	}
	current->next = first;
	first->next = NULL;
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = (*stack);
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = (*stack);
	tmp->next = NULL;
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}