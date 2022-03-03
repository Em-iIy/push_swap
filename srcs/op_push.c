/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:22:41 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/03 13:06:34 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b(t_stack *stack)
{
	t_node	*temp;

	if (!stack->stack_a)
		return (0);
	temp = stack->stack_a->next;
	node_add_front(&stack->stack_b, stack->stack_a);
	stack->stack_a = temp;
	return (1);
}

int	push_a(t_stack *stack)
{
	t_node	*temp;

	if (!stack->stack_b)
		return (0);
	temp = stack->stack_b->next;
	node_add_front(&stack->stack_a, stack->stack_b);
	stack->stack_b = temp;
	return (1);
}
