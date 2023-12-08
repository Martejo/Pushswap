/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:08:01 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/08 17:02:35 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

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


/*****error_manager*****/
bool	error_syntax(const char *str);
bool	error_duplicate(t_stack_node *a, int n);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **a, char *error_msg);

/*****Init_stack*****/
void	init_stack(t_stack_node **stack, char **argv);


/*****Stack_utils*****/
bool	stack_is_sorted(t_stack_node *stack);
size_t	stack_size(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);

/*****Sort_three*****/
void	sort_three(t_stack_node **stack);


#endif