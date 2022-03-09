/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:20:27 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/09 15:42:40 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static char	*op_str(int code)
{
	if (code == OP_PA)
		return (ft_strdup("pa\n"));
	else if (code == OP_PB)
		return (ft_strdup("pb\n"));
	else if (code == OP_SA)
		return (ft_strdup("sa\n"));
	else if (code == OP_SB)
		return (ft_strdup("sb\n"));
	else if (code == OP_SS)
		return (ft_strdup("ss\n"));
	else if (code == OP_RA)
		return (ft_strdup("ra\n"));
	else if (code == OP_RB)
		return (ft_strdup("rb\n"));
	else if (code == OP_RR)
		return (ft_strdup("rr\n"));
	else if (code == OP_RRA)
		return (ft_strdup("rra\n"));
	else if (code == OP_RRB)
		return (ft_strdup("rrb\n"));
	else if (code == OP_RRR)
		return (ft_strdup("rrr\n"));
	return (NULL);
}

static int	choose(t_stack *stack, int code)
{
	if (code == OP_PA)
		return (push_a(stack));
	else if (code == OP_PB)
		return (push_b(stack));
	else if (code == OP_SA)
		return (swap_a(stack));
	else if (code == OP_SB)
		return (swap_b(stack));
	else if (code == OP_SS)
		return (swap_ab(stack));
	else if (code == OP_RA)
		return (rotate_a(stack));
	else if (code == OP_RB)
		return (rotate_b(stack));
	else if (code == OP_RR)
		return (rotate_ab(stack));
	else if (code == OP_RRA)
		return (rrotate_a(stack));
	else if (code == OP_RRB)
		return (rrotate_b(stack));
	else if (code == OP_RRR)
		return (rrotate_ab(stack));
	return (0);
}

int	choose_op(t_stack *stack, int code)
{
	char	*temp;

	if (choose(stack, code))
	{
		temp = op_str(code);
		if (!temp)
			error_exit(MALLOC_ERROR);
		ft_putstr_fd(temp, 1);
		free(temp);
		return (1);
	}
	return (0);
}
