/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:23:01 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/08 10:44:36 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_stack *stack)
{
	t_node	*temp;

	if (!stack->stack_a)
		return (0);
	temp = stack->stack_a;
	stack->stack_a = stack->stack_a->next;
	temp->next = NULL;
	node_add_back(&stack->stack_a, temp);
	return (1);
}

int	rotate_b(t_stack *stack)
{
	t_node	*temp;

	if (!stack->stack_b)
		return (0);
	temp = stack->stack_b;
	stack->stack_b = stack->stack_b->next;
	temp->next = NULL;
	node_add_back(&stack->stack_b, temp);
	return (1);
}

int	rotate_ab(t_stack *stack)
{
	if (rotate_a(stack))
	{
		if (rotate_b(stack))
			return (1);
		rrotate_a(stack);
	}
	return (0);
}
