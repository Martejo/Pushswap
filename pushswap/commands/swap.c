/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:41:43 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/22 11:40:02 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

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

void	sa(t_stack_node **a, bool print)
{
	swap_node(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool print)
{
	swap_node(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
		swap_node(a);
		swap_node(b);
		if (print)
			write(1, "ss\n", 3);
}