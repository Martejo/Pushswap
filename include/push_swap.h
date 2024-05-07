/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:08:01 by gemartel          #+#    #+#             */
/*   Updated: 2024/01/03 10:20:21 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
# include "commands.h"

/*****error_manager*****/
bool	error_syntax(const char *str);
bool	error_duplicate(t_stack *a, int n);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a, char *error_msg, char **str, bool free_mod);
void	free2d(char **str);

/*****Init_stack*****/
void	init_stack(t_stack **stack, char **argv, bool free_mod);
int		add_node(t_stack **stack, int n);

/*****Stack_utils*****/
bool	stack_is_sorted(t_stack *stack);
size_t	stack_size(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_last(t_stack *stack);

/*****Sort_three*****/
void	sort_three(t_stack **stack);

/*****Sort_stack*****/
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	sort_stack(t_stack **a, t_stack **b);

/*****Sort_utils*****/
void	set_target_for_a(t_stack *a, t_stack *b);
void	set_target_for_b(t_stack *a, t_stack *b);
void	init_index(t_stack *stack);
void	push_cost_analysis(t_stack *a, t_stack *b);
void	find_cheapest(t_stack *stack);

/*****Sort_utils2*****/
void	*get_cheapeast(t_stack *stack);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	min_on_top(t_stack **a);

#endif