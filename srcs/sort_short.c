/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:01:38 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/08 16:37:47 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	start;
	int	mid;
	int	end;

	start = stack->stack_a->idx;
	mid = stack->stack_a->next->idx;
	end = stack->stack_a->next->next->idx;
	if (start < mid && mid > end && start < end)
	{
		choose_op(stack, OP_PB);
		choose_op(stack, OP_SA);
		choose_op(stack, OP_PA);
	}
	if (start > mid && mid < end && start < end)
		choose_op(stack, OP_SA);
	else if (start < mid && mid > end && start > end)
		choose_op(stack, OP_RRA);
	else if (start > mid && mid < end && start > end)
		choose_op(stack, OP_RA);
	else if (start > mid && mid > end && start > end)
	{
		choose_op(stack, OP_RA);
		choose_op(stack, OP_SA);
	}
}

void	sort_four(t_stack *stack, int idx)
{
	if (is_sorted(*stack))
		return ;
	if (stack->stack_a->next->next->next->idx == idx)
		choose_op(stack, OP_RRA);
	if (stack->stack_a->next->next->idx == idx)
		choose_op(stack, OP_RA);
	if (stack->stack_a->next->idx == idx)
		choose_op(stack, OP_RA);
	choose_op(stack, OP_PB);
	sort_three(stack);
	choose_op(stack, OP_PA);
}

void	sort_five(t_stack *stack)
{
	if (is_sorted(*stack))
		return ;
	if (stack->stack_a->next->next->next->idx == 0)
		choose_op(stack, OP_RRA);
	if (stack->stack_a->next->next->next->next->idx == 0)
		choose_op(stack, OP_RRA);
	if (stack->stack_a->next->next->idx == 0)
		choose_op(stack, OP_RA);
	if (stack->stack_a->next->idx == 0)
		choose_op(stack, OP_RA);
	choose_op(stack, OP_PB);
	sort_four(stack, 1);
	choose_op(stack, OP_PA);
}
