/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:27:52 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/03 12:47:43 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

// Error codes
enum e_error
{
	MALLOC_ERROR = -1,
	TOO_FEW_ARGUMENTS = 1
};

typedef struct s_node
{
	char			*num;
	struct s_node	*next;
}	t_node;

// Stack
typedef struct s_stack
{
	t_node	*stack_a;
	t_node	*stack_b;
}	t_stack;

// Errors
void	error_exit(int code);

// Node utils
t_node	*node_new(char *num);
t_node	*node_last(t_node *node);
void	node_add_back(t_node **node, t_node *new);
void	node_add_front(t_node **node, t_node *new);
size_t	node_size(t_node *node);

// Parsing input
void	parse_input(t_stack *stack, int argc, char **argv);
int		parse_input_bin(int argc, char **argv);

// Operations
// Push
void	push_b(t_stack *stack);
void	push_a(t_stack *stack);

#endif