/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:27:52 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/23 18:05:59 by gwinnink         ###   ########.fr       */
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

// Errors
void	error_exit(int code);

// Parsing input
void	parse_input(t_stack *stack, int argc, char **argv);
int		parse_input_bin(int argc, char **argv);

#endif