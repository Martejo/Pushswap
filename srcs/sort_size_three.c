/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:45:29 by gemartel          #+#    #+#             */
/*   Updated: 2024/01/03 10:08:16 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*max;

	if (!stack)
		return ;
	max = find_max(*stack);
	if (*stack == max)
		ra(stack, true);
	else if ((*stack)->next == max)
		rra(stack, true);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, true);
}
