/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:08:01 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/22 12:19:39 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


# include <stdbool.h>
#include <stdio.h>


typedef struct	s_stack_node
{
	int	nbr;
	int	index;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	struct	s_stack_node	*target_node;
	struct	s_stack_node	*next;
} t_stack_node;


# include <limits.h>
# include "../libft/libft.h"
# include "commands.h"

/*****error_manager*****/
bool	error_syntax(const char *str);
bool	error_duplicate(t_stack_node *a, int n);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **a, char *error_msg, char **str, bool free_mod);
void	free2d(char **str);

/*****Init_stack*****/
void	init_stack(t_stack_node **stack, char **argv, bool free_mod);
int	add_node(t_stack_node **stack, int n);



/*****Stack_utils*****/
bool	stack_is_sorted(t_stack_node *stack);
size_t	stack_size(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);

/*****Sort_three*****/
void	sort_three(t_stack_node **stack);

/*****Sort_stack*****/
void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);
void	sort_stack(t_stack_node **a , t_stack_node **b);

/*****Sort_utils*****/
void	set_target_for_a(t_stack_node *a, t_stack_node *b);
void	set_target_for_b(t_stack_node *a, t_stack_node *b);
void	init_index(t_stack_node *stack);
void	push_cost_analysis(t_stack_node *a, t_stack_node  *b);
void	find_cheapest(t_stack_node *stack);

/*****Sort_utils2*****/
void	*get_cheapeast(t_stack_node *stack);
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void	min_on_top(t_stack_node **a);




#endif