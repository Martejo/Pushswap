/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:13:07 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/22 12:58:53 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int	do_commands(char *line, t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a, false);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b, false);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b, false);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b, false);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, false);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a, false);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b, false);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b, false);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a, false);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b, false);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b, false);
	else
		return (0);
	return (1);
}

void	init_stack_checker(t_stack_node **stack, char **argv, bool free_mod)
{
	long	n;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(stack, "Error\n", argv, free_mod);
		n = ft_atol(argv[i]);
		printf("n = %ld", n);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(stack, "Error\n", argv, free_mod);
		if (error_duplicate(*stack, (int)n))
			free_errors(stack, "Error\n", argv, free_mod);
		if (!add_node(stack, (int)n))
			free_errors(stack, "Error\n", argv, free_mod);
		i++;
	}
	if (free_mod)
		free2d(argv);
}


void	checker_res(t_stack_node **a, t_stack_node **b)
{
	if (stack_is_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (*a)
		free_stack(a);
	if (*b)
		free_stack(b);
}
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*line;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		init_stack(&a, ft_split(argv[1], ' '), true);
	else
		init_stack(&a, argv + 1, false);
	
	line = get_next_line(0);
	while (line != NULL)
	{
			if (do_commands(line, &a, &b) == 0)
			{
				free_stack(&b);
				free_errors(&a, "Error", NULL, false);
			}
			free(line);
			line = get_next_line(0);
	}
	checker_res(&a, &b);
	return (0);
}