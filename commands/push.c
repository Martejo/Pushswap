/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:36:51 by gemartel          #+#    #+#             */
/*   Updated: 2024/01/03 10:06:39 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_node(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!(*src))
		return ;
	tmp = (*src);
	(*src) = (*src)->next;
	tmp->next = (*dest);
	(*dest) = tmp;
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push_node(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push_node(b, a);
	if (print)
		write(1, "pb\n", 3);
}
