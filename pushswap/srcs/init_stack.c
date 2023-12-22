/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:43:51 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/21 17:29:39 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node(t_stack_node **stack, int n)
{
	t_stack_node *node;
	t_stack_node *last_node;
	
	if (!stack)
		return (-1);
	node = (t_stack_node*)malloc(1 * sizeof(t_stack_node));
	if (!node)
		return (-1);
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
	}
	return (1);
}


void	init_stack(t_stack_node **stack, char **argv, bool free_mod)
{
	long	n;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(stack, "Wrong syntax, please try again.\n", argv, free_mod);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(stack, "Error: int overflow.\n", argv, free_mod);
		if (error_duplicate(*stack, (int)n))
			free_errors(stack, "Error: duplicate number.\n", argv, free_mod);
		if (!add_node(stack, (int)n))
			free_errors(stack, "Malloc error.\n", argv, free_mod);
		i++;
	}
	if (free_mod)
		free2d(argv);
}