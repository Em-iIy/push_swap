/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:22:59 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/07 14:34:46 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_stack *stack)
{
	t_node	*temp;

	if (!stack->stack_a || !stack->stack_a->next)
		return (0);
	temp = stack->stack_a->next->next;
	node_add_front(&stack->stack_a, stack->stack_a->next);
	stack->stack_a->next->next = temp;
	return (1);
}

int	swap_b(t_stack *stack)
{
	t_node	*temp;

	if (!stack->stack_b || !stack->stack_b->next)
		return (0);
	temp = stack->stack_b->next->next;
	node_add_front(&stack->stack_b, stack->stack_b->next);
	stack->stack_b->next->next = temp;
	return (1);
}

int	swap_ab(t_stack *stack)
{
	if (swap_a(stack))
	{
		if (swap_b(stack))
			return (1);
		swap_a(stack);
	}
	return (0);
}
