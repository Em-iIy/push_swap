/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:00:14 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/08 13:20:02 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack stack)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = stack.stack_a;
	stack_b = stack.stack_b;
	printf("A\tB\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%d", stack_a->num);
			stack_a = stack_a->next;
		}
		if (stack_b)
		{
			printf("\t%d", stack_b->num);
			stack_b = stack_b->next;
		}
		printf("\n");
	}
}
