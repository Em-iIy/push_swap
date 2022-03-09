/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:10:21 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/09 15:40:12 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	check_num(int argc, char **argv)
{
	int		i;
	int		j;
	char	tmp;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			tmp = argv[i][j];
			if (tmp == '-' && !ft_isdigit(argv[i][j + 1]))
				error_exit(INVALID_ARGUMENT);
			else if (tmp != '-' && !ft_isdigit(tmp))
				error_exit(INVALID_ARGUMENT);
			j++;
		}
		i++;
	}
}

static void	indexing(t_node **stack_a, int argc)
{
	t_node	smallest;
	t_node	*iterator;
	long	temp;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		iterator = *stack_a;
		temp = 2147483648;
		while (iterator)
		{
			if (iterator->num < temp && iterator->idx == -1)
			{
				smallest.next = iterator;
				temp = iterator->num;
			}
			iterator = iterator->next;
		}
		smallest.next->idx = i;
		i++;
	}
}

static void	fill_stack_a(t_node **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		node_add_back(stack_a, node_new(ft_atoi(argv[i])));
		i++;
	}
	indexing(stack_a, argc);
}

static void	check_dup(t_node *stack_a)
{
	t_node	*i;

	while (stack_a->next)
	{
		i = stack_a->next;
		while (i)
		{
			if (stack_a->num == i->num)
				error_exit(DUPLICATE_ARGUMENT);
			i = i->next;
		}
		stack_a = stack_a->next;
	}
}

void	parse_input(t_stack *stack, int argc, char **argv)
{
	check_num(argc, argv);
	if (argc == 2)
		exit (0);
	fill_stack_a(&stack->stack_a, argc, argv);
	check_dup(stack->stack_a);
}
