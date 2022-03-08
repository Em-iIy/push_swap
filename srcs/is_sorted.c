/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:49:13 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/08 17:50:02 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack stack)
{
	t_node	*stack_a;

	stack_a = stack.stack_a;
	while (stack_a->next)
	{
		if (stack_a->idx > stack_a->next->idx)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
