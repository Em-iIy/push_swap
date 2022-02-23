/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:27:52 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/23 16:07:02 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Error codes
enum e_error
{
	MALLOC_ERROR = -1,
	TOO_FEW_ARGUMENTS = 1
};

typedef struct s_node
{
	char	*num;
	void	*next;
}	t_node;

// Stack
typedef struct s_stack
{
	t_node	*stack_a;
	t_node	*stack_b;
}	t_stack;

void	error_exit(int code);

#endif