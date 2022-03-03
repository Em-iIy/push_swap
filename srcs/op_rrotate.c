/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:23:10 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/03 18:53:14 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrotate_a(t_stack *stack)
{
	t_node	*temp;

	if (!stack->stack_a)
		return (0);
	temp = stack->stack_a;
	stack->stack_a = node_last(stack->stack_a);
	stack->stack_a->next = temp;
	while (temp->next != stack->stack_a)
		temp = temp->next;
	temp->next = NULL;
	return (1);
}

int	rrotate_b(t_stack *stack)
{
	t_node	*temp;

	if (!stack->stack_b)
		return (0);
	temp = stack->stack_b;
	stack->stack_b = node_last(stack->stack_b);
	stack->stack_b->next = temp;
	while (temp->next != stack->stack_b)
		temp = temp->next;
	temp->next = NULL;
	return (1);
}

int	rrotate_ab(t_stack *stack)
{
	if (rrotate_a(stack))
	{
		if (rrotate_b(stack))
			return (1);
		rotate_a(stack);
	}
	return (0);
}
