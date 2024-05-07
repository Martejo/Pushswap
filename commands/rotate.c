/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:28:24 by gemartel          #+#    #+#             */
/*   Updated: 2024/01/03 10:15:31 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = find_last(*stack);
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a, bool print)
{
	rotate_stack(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool print)
{
	rotate_stack(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate_stack(a);
	rotate_stack(b);
	if (print)
		write(1, "rr\n", 3);
}
