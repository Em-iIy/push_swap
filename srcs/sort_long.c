/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:33 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/09 15:42:54 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int n)
{
	int	i;

	i = 0;
	while (n >> i)
		i++;
	return (i);
}

void	sort_long(t_stack *stack, int stack_len)
{
	int		i;
	int		j;
	int		bits;

	i = 0;
	bits = count_bits(stack_len - 1);
	while (i < bits)
	{
		j = 0;
		while (j < stack_len)
		{
			if (!((stack->stack_a->idx >> i) & 1))
				choose_op(stack, OP_PB);
			else
				choose_op(stack, OP_RA);
			j++;
		}
		while (stack->stack_b)
			choose_op(stack, OP_PA);
		i++;
	}
}
