/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:22:41 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/03 12:52:59 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack)
{
	t_node	*temp;

	if (!stack->stack_a)
		return ;
	temp = stack->stack_a->next;
	node_add_front(&stack->stack_b, stack->stack_a);
	stack->stack_a = temp;
}

void	push_a(t_stack *stack)
{
	t_node	*temp;

	if (!stack->stack_b)
		return ;
	temp = stack->stack_b->next;
	node_add_front(&stack->stack_a, stack->stack_b);
	stack->stack_b = temp;
}
