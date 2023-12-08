/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:13:02 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/08 17:03:21 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		init_stack(&a, ft_split(argv[1], ' '));
	else
		init_stack(&a, argv + 1);
	if (!stack_is_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a); // print et a voir
		else if (stack_size(a) == 3)
			sort_three(a);
		else
			sort_stack(&a, &b);
	}
	free_stack(a);
	return (0);
}