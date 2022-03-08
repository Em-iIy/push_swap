/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:27:52 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/08 16:33:46 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

// Error codes
enum e_error
{
	MALLOC_ERROR = -1,
	TOO_FEW_ARGUMENTS = 1,
	INVALID_ARGUMENT = 2,
	DUPLICATE_ARGUMENT = 3
};

// Operation names
enum e_op
{
	OP_PA,
	OP_PB,
	OP_SA,
	OP_SB,
	OP_SS,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
};

typedef struct s_node
{
	int				num;
	int				idx;
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
t_node	*node_new(int num);
t_node	*node_last(t_node *node);
void	node_add_back(t_node **node, t_node *new);
void	node_add_front(t_node **node, t_node *new);
size_t	node_size(t_node *node);

// Parsing input
void	parse_input(t_stack *stack, int argc, char **argv);
int		parse_input_bin(int argc, char **argv);

// Operations
char	*choose_op(t_stack *stack, int code);
// Push (pa, pb)
int		push_b(t_stack *stack);
int		push_a(t_stack *stack);
// Swap (sa, sb, ss)
int		swap_a(t_stack *stack);
int		swap_b(t_stack *stack);
int		swap_ab(t_stack *stack);
// Rotate (ra, rb, rr)
int		rotate_a(t_stack *stack);
int		rotate_b(t_stack *stack);
int		rotate_ab(t_stack *stack);
// Reverse Rotate (rra, rrb, rrr)
int		rrotate_a(t_stack *stack);
int		rrotate_b(t_stack *stack);
int		rrotate_ab(t_stack *stack);

// Sorting
// check if stack is sorted
int		is_sorted(t_stack stack);
// short stacks (3 to 5)
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack, int idx);
void	sort_five(t_stack *stack);

void	print_stack(t_stack stack);

#endif