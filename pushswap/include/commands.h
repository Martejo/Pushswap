/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:33:37 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/22 11:40:30 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
#define COMMANDS_H



/*****Rotate*****/
void	rotate_stack(t_stack_node **stack);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);

/*****Push*****/
void	push_node(t_stack_node **dest, t_stack_node **src);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **a, t_stack_node **b, bool print);

/*****Swap*****/
void	swap_node(t_stack_node **stack);
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);

/*****Rev_rotate*****/
void	reverse_rotate(t_stack_node **stack);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);

#endif