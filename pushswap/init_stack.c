/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:43:51 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/08 16:04:33 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	add_node(t_stack_node **stack, int n)
{
	t_stack_node *node;
	t_stack_node *last_node;
	
	if (!stack)
		return ;
	node = (t_stack_node*)malloc(1 * sizeof(t_stack_node));
	if (!node)
		free_errors(stack, "Malloc error.\n");
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
		*stack = node;
	else
	{
		
	}
	
}


void	init_stack(t_stack_node **stack, char **argv)
{
	long	n;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(stack, "Wrong syntax, please try again.\n");
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(stack, "Error: int overflow.\n");
		if (error_duplicate(*stack, (int)n))
			free_errors(stack, "Error: duplicate number.\n");
		add_node(stack, (int)n);
		i++;
	}
}