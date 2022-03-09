/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:12:19 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/09 10:29:46 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack *stack, int stack_len)
{
	if (is_sorted(*stack))
		return ;
	if (stack_len == 2)
		choose_op(stack, OP_SA);
	else if (stack_len == 3)
		sort_three(stack);
	else if (stack_len == 4)
		sort_four(stack, 0);
	else if (stack_len == 5)
		sort_five(stack);
}