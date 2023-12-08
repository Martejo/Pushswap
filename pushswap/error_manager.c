/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:28:45 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/08 15:48:04 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	error_syntax(const char *str)
{
	int i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || !ft_isdigit(str[i])))
		return (true);
	if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
		return (true); // a voir plus tard
	while (str[++i])
	{
		if (!(ft_isdigit(str[i])))
			return (true);
	}
	return (false);
}

bool	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->nbr == n)
			return (true);
		a = a->next;
	}
	return (false);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;
	
	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a, char *error_msg)
{
	free_stack(a);
	ft_putstr_fd(error_msg, 2);
	exit(EXIT_FAILURE);
}